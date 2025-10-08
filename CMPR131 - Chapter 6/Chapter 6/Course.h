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
