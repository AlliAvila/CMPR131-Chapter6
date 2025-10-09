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

	// Precondition: N/A
	// Postcondition: Return the course name
    string getCourseName() const
    {
        return courseName;
    }

	// Precondition: User provides a valid course name
	// Postcondition: set courseName to name
    void setCourseName(const string& name)
    {
        courseName = name;
    }

	// Precondition: N/A
	// Postcondition: Return the number of students in the course
    int getSize() const
    {
        return studentIDs.getSize();
    }

    // Add new student record
	// Precondition: User provides valid student details
	// Postcondition: Add student details to respective arrays in MyBags
    void addStudent(int id, const string& name, double score, char grade)
    {
        studentIDs.insert(id);
        studentNames.insert(name);
        studentScores.insert(score);
        studentGrades.insert(grade);
    }

    // Remove a student by ID
	// Precondition: User provides a valid student ID
	// Postcondition: Remove student details from respective MyBags if ID found
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
	// Precondition: User provides a valid student name
	// Postcondition: Remove student details from respective MyBags if name found
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
	// Precondition: User provides a valid student ID
	// Postcondition: Return the index of the student if found, otherwise -1
    int searchStudentByID(int id) const
    {
        return studentIDs.linearSearch(id);
    }

    // Search by Name
	// Precondition: User provides a valid student name
	// Postcondition: Return the index of the student if found, otherwise -1
    int searchStudentByName(const string& name) const
    {
        return studentNames.linearSearch(name);
    }

    // Load course + students from text file
	// Precondition: User provides a valid filename
	// Postcondition: Load course name and student details from file into addStudent method
    bool loadFromFile(const string& filename)
    {
        ifstream inFile(filename);

        if (!inFile)
        {
            cerr << "\n\tERROR: File, " << filename << ", cannot be found. Please re-specify.\n";
            return false;
        }

        inFile >> courseName;

        int id;
        string name;
        double score;
        char grade;

        while (inFile >> id >> name >> score >> grade)
        {
            addStudent(id, name, score, grade);
        }

        inFile.close();
        return true;
    }

    // Comparison operator (for sorting)
	// Precondition: N/A
	// Postcondition: Compare two Course objects based on courseName
    bool operator<(const Course& other) const
    {
        return courseName < other.courseName;
    }

    // Friend function for output
	// Precondition: N/A
	// Postcondition: Friend function-Output course details in a formatted manner
    friend ostream& operator<<(ostream& out, const Course& c)
    {
        out << "Course: " << c.courseName << " (" << c.studentIDs.getSize() << " students)";
        return out;
    }
};
