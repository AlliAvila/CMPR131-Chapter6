#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "MyBag.h"
#include "MyBagTemplate.h"
using namespace std;

class Course
{
private:
    string courseName;
    MyBagTemplate<int> studentIDs;
    MyBagTemplate<string> studentNames;
    MyBagTemplate<double> studentScores;
    MyBagTemplate<char> studentGrades;

public:
    // Constructors & Destructor
    Course() : courseName("") {}
    Course(string name) : courseName(name) {}
    ~Course() {}

    // Accessors
    string getCourseName() const 
    { 
        return courseName; 
    }

    void setCourseName(const string& name) 
    { 
        courseName = name; 
    }

    int getSize() const 
    { 
        return studentIDs.getSize(); 
    }

    // Add new student record
    void addStudent(int id, const string& name, double score, char grade)
    {
        studentIDs.insert(id);
        studentNames.insert(name);
        studentScores.insert(score);
        studentGrades.insert(grade);
    }

    // Remove a student by ID
    bool removeStudentByID(int id)
    {
        int index = studentIDs.linearSearch(id);

        if (index == -1)
        {
            return false;
        }

        studentIDs.remove(index);
        studentNames.remove(index);
        studentScores.remove(index);
        studentGrades.remove(index);
        return true;
    }

    // Remove a student by name
    bool removeStudentByName(const string& name)
    {
        int index = studentNames.linearSearch(name);

        if (index == -1)
        {
            return false;
        }

        studentIDs.remove(index);
        studentNames.remove(index);
        studentScores.remove(index);
        studentGrades.remove(index);
        return true;
    }

    // Search by ID
    int searchStudentByID(int id) const
    {
        return studentIDs.linearSearch(id);
    }

    // Search by Name
    int searchStudentByName(const string& name) const
    {
        return studentNames.linearSearch(name);
    }

    // Load course + students from text file
bool loadFromFile(const string& filename)
{
    ifstream inFile(filename);

    if (!inFile)
    {
        cout << "\n\tERROR: File, " << filename << ", cannot be found. Please re-specify.\n";
        return false;
    }

    // Read first line for course name
    getline(inFile, courseName);

    string line;
    while (getline(inFile, line))
    {
        if (line.empty())
        {
            continue; // skip any blank lines
        }

        vector<string> tokens;
        split(line, ',', tokens);

        // Expected format: ID, Name, Score
        if (tokens.size() != 3)
        {
            continue; // skip malformed lines safely
        }

        int id = stoi(tokens[0]);
        string name = tokens[1];
        double score = stod(tokens[2]);

        // Calculate grade
        char grade = calculateGrade(score);

        // Add student record
        addStudent(id, name, score, grade);
    }

    inFile.close();
    return true;
}

//Precondition: s is a string to be split, delim is the delimiter character, and tokens is a vector to store the split tokens.
//Postcondition: The string s is split into tokens based on the delimiter delim, and the tokens are stored in the vector tokens.
void split(const string& s, char delim, vector<string>& tokens)
{
    // starting position of the next token
    int tokenStart = 0;

    // Find the first occurrence of the delimiter
    int delimPosition = s.find(delim);

    // While not ran out of delimiters
    while (delimPosition != string::npos)
    {
        // Extracts the token
        string tok = s.substr(tokenStart, delimPosition - tokenStart);

        // Push the token onto the tokens vector
        tokens.push_back(tok);

        // Move delimPosition to the next character position
        delimPosition++;
        // move token start to delimPosition
        tokenStart = delimPosition;

        // Find the next occurrence of the delimiter
        delimPosition = s.find(delim, delimPosition);

        // if no more delimiters, extract the last token
        if (delimPosition == string::npos)
        {
            // Extract the token
            string tok = s.substr(tokenStart, delimPosition - tokenStart);

            // Push the token onto the vector
            tokens.push_back(tok);
        }
    }
}

char calculateGrade(double score)
{
    if (score >= 90)
    {
        return 'A';
    }
    else if (score >= 80)
    {
        return 'B';
    }
    else if (score >= 70)
    {
        return 'C';
    }
    else if (score >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

double calculateAverageScore()
{
    if (studentScores.getSize() == 0)
    {
        return 0.0; // avoid division by zero
    }

    double total = 0.0;

    for (int i = 0; i < studentScores.getSize(); i++)
    {
        total += studentScores[i]; 
    }

    return total / studentScores.getSize();
}
    // Comparison operator (for sorting)
    bool operator<(const Course& other) const
    {
        return courseName < other.courseName;
    }

    // Friend function for output
    friend ostream& operator<<(ostream& out, const Course& c)
    {
        out << "Course: " << c.courseName << " (" << c.studentIDs.getSize() << " students)";
        return out;
    }
};
