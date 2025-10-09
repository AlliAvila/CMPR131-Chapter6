#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
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
	//Precondition: N/A
	//Postcondition: Returns the course name
    string getCourseName() const
    {
        return courseName;
    }

	//Mutators
	//Precondition: Same is a valid string
	//Postcondition: Sets the course name to the provided name
    void setCourseName(const string& name)
    {
        courseName = name;
    }

	//Precondition: N/A
	//Postcondition: Returns the current number of student records in the course
    int getSize() const
    {
        return studentIDs.getSize();
    }

    // Add new student record
	// Precondition: id is a valid integer, name is a valid string, score is a valid double between 0 and 100, grade is a valid char (A-F)
	// Postcondition: A new student record is added to the course
    void addStudent(int id, const string& name, double score, char grade)
    {
        studentIDs.insert(id);
        studentNames.insert(name);
        studentScores.insert(score);
        studentGrades.insert(grade);
    }

    // Remove a student by ID
	// Precondition: id is a valid integer for search
	// Postcondition: Returns true if the student was found and removed, false otherwise
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
	// Precondition: name is a valid string for search
	// Postcondition: Returns true if the student was found and removed, false otherwise
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
	// Precondition: id is a valid integer for search
	// Postcondition: Returns the index of the student if found
    int searchStudentByID(int id) const
    {
        return studentIDs.linearSearch(id);
    }

    // Search by Name
	// Precondition: Name is a valid string for search 
	// Postcondition: Returns the name of the student if found
    int searchStudentByName(const string& name) const
    {
        return studentNames.linearSearch(name);
    }

    // Load course + students from text file
	// Precondition: filename is a valid file path to a file with course and student data.
	// Postcondition: The course name and student records are loaded from the file into the Course object. Returns true if successful, false otherwise.
    bool loadFromFile(const string& filename)
{
    ifstream inFile(filename);

    if (!inFile)
    {
        cout << "\n\tERROR: Could not open file: " << filename << endl;
        return false;
    }

    // Read course name (first line)
    getline(inFile, courseName);

    string line;
    while (getline(inFile, line))
    {
        if (line.empty())
        {
            continue; // skip blank lines
        }

        vector<string> tokens;
        split(line, ',', tokens);

        if (tokens.size() != 3)
        {
            continue; // make sure there are exactly 3 tokens: ID, Name, Score
        }

        int id = stoi(tokens[0]);
        string name = tokens[1];
        double score = stod(tokens[2]);
        char grade = calculateGrade(score);

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

	// Calculate letter grade from score
	// Precondition: score is a valid double between 0 and 100.
	// Postcondition: Returns the corresponding letter grade based on the score.
    char calculateGrade(double score) const
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

	// Calculate average score
	// Precondition: There is at least one student score in the course.
	// Postcondition: Returns the average score of all students in the course.
    double calculateAverageScore() const
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
	// Precondition: Other is another Course object to compare with.
	// Postcondition: Returns true if this course's name is alphabetically/numerically before than the other course's name.
    bool operator<(const Course& other) const
    {
        return courseName < other.courseName;
    }

	//Friend function to overload the output stream operator for Course class
    friend ostream& operator<<(ostream& out, const Course& c);
};

//Precondition: out is a valid output stream and c is a Course object.
//Postcondition: The details of the Course object c are displayed in a formatted manner.
ostream& operator<<(ostream& out, const Course& c)
{
    out << "\n\t" << c.courseName;
    out << "\n\t" << string(80, char(196));
    out << "\n\t" << setw(10) << "Index"
        << setw(15) << "StudentID"
        << setw(30) << "Name"
        << setw(10) << "Score"
        << setw(8) << "Grade";

    out << "\n\t" << string(80, char(196));

    for (int i = 0; i < c.getSize(); i++)
    {
        out << "\n\t"
            << setw(10) << i
            << setw(15) << c.studentIDs[i]
            << setw(30) << c.studentNames[i]
            << setw(10) << fixed << setprecision(1) << c.studentScores[i]
            << setw(8) << c.studentGrades[i];
    }

    out << "\n\n\tAverage score and grade: "
        << fixed << setprecision(1) << c.calculateAverageScore()
        << "(" << c.calculateGrade(c.calculateAverageScore()) << ")\n";

    return out;
}
