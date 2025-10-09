// Names: Allison Avila, Hayden Martinez, David Derramadero
// Date : Started 10/04/2025
// Chapter 6 - Assignments 
#include <iostream>
#include "input.h"
#include "MyBag.h"
#include "MyBagTemplate.h"
#include "Course.h"

using namespace std;

void option1();
void option2();
void option3();

int main()
{
	do
	{
		system("cls");
		cout << "\n\tCMPR131 Chapter 6: non-template and template Container";
		cout << "\n\t" << string(65, char(205));
		cout << "\n\t\t1> Non-template MyBag container of int";
		cout << "\n\t\t2> Template MyBag<double> container";
		cout << "\n\t\t3> Application using MyBag container";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t" << string(65, char(205));
		switch (inputInteger("\n\t\tOption: ", 0, 3))
		{
		case 0: exit(0);
		case 1: option1(); break;
		case 2: option2(); break;
		case 3: option3(); break;
		}



	} while (true);


	return 0;
}
void option1()
{
	MyBag bag;
	do
	{
		system("cls");
		cout << "\n\t1> Non-template MyBag of integers";
		cout << "\n\t" << string(65, char(205));
		cout << "\n\t\tA> clear";
		cout << "\n\t\tB> insert";
		cout << "\n\t\tC> search";
		cout << "\n\t\tD> remove";
		cout << "\n\t\tE> sort";
		cout << "\n\t\tF> display";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(65, char(205));
		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("abcdef0"))))
		{
		case '0': return; break;
		case 'A':
		{
			try
			{
				bag.clear();
				cout << "\n\t\tMyBag is cleared of all elements.\n.";
			}
			catch (string exceptionString)
			{
				cout << exceptionString;
			}

		}; break;
		case 'B':
		{
			int value = inputInteger("\n\t\tEnter a value and insert into MyBag: ");
			bag.insert(value);
			cout << "\n\t\t" + to_string(value) + " has been inserted into MyBag.\n\n";

		}break;
		case 'C':
		{
			if (bag.getSize() != 0)
			{
				int value = inputInteger("\n\tEnter a value to search from MyBag: ");
				if (bag.linearSearch(value) != -1)
					cout << "\n\tValue " << value << " is found at subscript #" << bag.linearSearch(value) << " from MyBag.\n\n";
				else
					cout << "\n\tValue " << value << " is not found from MyBag.\n\n";
			}
			else
				cout << "\n\t\tMyBag is empty.\n\n";


		}break;
		case 'D':
		{
			if (bag.getSize() != 0)
			{
				int value = inputInteger("\n\tEnter an index(subscript) from MyBag to be deleted: ", 0, bag.getSize() - 1);
				cout << "\n\tValue " + to_string(bag[value]) + " has been deleted from MyBag.\n\n";
				bag.remove(value);
			}
			else
				cout << "\n\t\tMyBag is empty.\n\n";

		}break;
		case 'E':
		{
			bag.sortBag();

		}break;
		case 'F':
		{
			try
			{
				cout << bag;
			}
			catch (string exceptionString)
			{
				cout << exceptionString;
				break;
			}

		}break;

		}
		system("pause");
	} while (true);


}
void option2()
{
	do
	{
		system("cls");
		cout << "\n\t2> Non-template MyBag of integers";
		cout << "\n\t" << string(65, char(205));
		cout << "\n\t\tA> clear";
		cout << "\n\t\tB> insert";
		cout << "\n\t\tC> search";
		cout << "\n\t\tD> remove";
		cout << "\n\t\tE> sort";
		cout << "\n\t\tF> display";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(65, char(205));
		switch (inputChar("\n\t\tOption: ", static_cast<string>("abcdef0")))
		{
		case '0': return; break;
		case 'A': break;
		case 'B': break;
		case 'D': break;
		case 'E': break;
		case 'F': break;
		case 'C': break;

		}
	} while (true);
}

void option3()
{
	Course* courses = nullptr;
	int numCourses = 0;
	string filename;
	bool coursesCreated = false;
	bool exitOption3 = false; // flag to exit outer option3 menu

	do
	{
		system("cls");
		cout << "\n\t3) Courses using MyBags of integers, strings, doubles, and chars";
		cout << "\n\t" << string(65, char(205));
		cout << "\n\t\t1> Specify the number of courses";
		cout << "\n\t\t2> Read in data file and insert into courses";
		cout << "\n\t\t3> Search for a student record from a course";
		cout << "\n\t\t4> Remove a student record from a course";
		cout << "\n\t\t5> Display course(s)";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t\t0> Return";
		cout << "\n\t" << string(65, char(205));
		switch (inputInteger("\n\t\tOption: ", 0, 5))
		{
		case 0:
		{
			delete[] courses;
			courses = nullptr;
			exitOption3 = true;
			return;
		}
		break;
		case 1:
		{
			numCourses = inputInteger("\n\tEnter the number of courses: ", true);
			coursesCreated = true;
			courses = new Course[numCourses];

			cout << "\n\t" << numCourses << " courses have been created.\n\n";
			system("pause");
		}
		break;
		case 2:
		{
			if (!coursesCreated)
			{
				cout << "\n\tERROR: Number of courses has not been assigned.\n\n";
				system("pause");
				break;
			}

			for (int i = 0; i < numCourses; i++)
			{
				filename = inputString("\n\tEnter a data file name for course[" + to_string(i) + "] (STOP - return): ", true);

				if (filename == "STOP")
				{
					break;
				}

				if (courses[i].loadFromFile(filename) == true)
				{
					cout << "\n\tData from file, " << filename << ", has been read and stored into courses[" << i << "].\n";
				}
				else
				{
					i--; // retry same course index
				}
			}

			cout << "\n";
			system("pause");
		}
		break;
		case 3:
		{
			if (!coursesCreated)
			{
				cout << "\n\tERROR: Number of courses has not been assigned.\n\n";
				system("pause");
				break;
			}

			bool exitSearch = false; // flag for inner search loop
			do
			{
				system("cls");
				cout << "\n\t3. Search By";
				cout << "\n\t" << string(65, char(205));
				cout << "\n\t\t1> ID Number";
				cout << "\n\t\t2> Name";
				cout << "\n\t" << string(65, char(196));
				cout << "\n\t\t0> Return";
				cout << "\n\t" << string(65, char(205));

				switch (inputInteger("\n\t\tOption: ", 0, 2))
				{
				case 0:
				{
					exitSearch = true;
					break;
				}
					break;
				case 1: // Search by ID
				{
					int id = inputInteger("\n\tEnter student ID to search for: ");
					bool found = false;

					for (int i = 0; i < numCourses; i++)
					{
						int index = courses[i].searchStudentByID(id);
						if (index != -1)
						{
							cout << "\n\tID: " << id
								<< " found in Course: "
								<< courses[i].getCourseName() << "\n";
							found = true;
						}
					}

					if (!found)
					{
						cout << "\n\tNo student found with ID " << id << ".\n";
					}

				} break;
				case 2: // Search by Name
				{
					string name = inputString("\n\tEnter student name to search for: ", true);
					bool found = false;

					for (int i = 0; i < numCourses; i++)
					{
						int index = courses[i].searchStudentByName(name);
						if (index != -1)
						{
							cout << "\n\t" << name
								<< " found in Course: "
								<< courses[i].getCourseName() << "\n";
							found = true;
						}
					}

					if (!found)
					{
						cout << "\n\tNo student found with name \"" << name << "\".\n";
					}

				} break;
				} 
				if (exitSearch) break;
				cout << "\n";
				system("pause");
			} while (true);
		}
		break;
		case 4:
		{
			if (!coursesCreated)
			{
				cout << "\n\tERROR: Number of courses has not been assigned.\n\n";
				system("pause");
				break;
			}

			bool exitRemove = false; // flag for inner remove loop
			do
			{
				system("cls");
				cout << "\n\t4. Remove Student Record";
				cout << "\n\t" << string(65, char(205));

				// Display all courses with index
				for (int i = 0; i < numCourses; i++)
				{
					cout << "\n\t\t" << (i + 1) << "> " << courses[i].getCourseName();
				}

				cout << "\n\t" << string(65, char(196));
				cout << "\n\t\t0> Return";
				cout << "\n\t" << string(65, char(205));

				// Ask user to pick 1..numCourses (0 to return)
				int courseChoice = inputInteger("\n\t\tOption: ", 0, numCourses);

				if (courseChoice == 0)
				{
					exitRemove = 0;
					break; 
				}

				// Adjust to 0-based index
				int courseIndex = courseChoice - 1;

				// Prompt for student ID in the selected course
				int studentID = inputInteger("\n\tEnter student ID to remove: ", true);

				if (courses[courseIndex].removeStudentByID(studentID))
				{
					cout << "\n\tStudent ID " << studentID
						<< " has been removed from course "
						<< courses[courseIndex].getCourseName() << ".\n";
				}
				else
				{
					cout << "\n\tERROR: Student ID " << studentID
						<< " not found in course "
						<< courses[courseIndex].getCourseName() << ".\n";
				}

				cout << "\n";
				system("pause");
			} while (!exitRemove);
		}
		break;
		case 5:
{
	if (!coursesCreated)
	{
		cout << "\n\tERROR: Number of courses has not been assigned.\n\n";
		system("pause");
		break;
	}

	while (true)
	{
		system("cls");
		cout << "\n\t5. Display Course Records";
		cout << "\n\t" << string(65, char(205));

		// Display course options
		for (int i = 0; i < numCourses; i++)
		{
			cout << "\n\t\t" << (i + 1) << "> " << courses[i].getCourseName();
		}
		cout << "\n\t\t" << (numCourses + 1) << "> Display All";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t\t0> Return";
		cout << "\n\t" << string(65, char(205));

		int choice = inputInteger("\n\t\tOption: ", 0, numCourses + 1);

		if (choice == 0)
		{
			break; // return to previous menu
		}

		else if (choice == numCourses + 1)
		{
			system("cls");
			for (int i = 0; i < numCourses; i++)
			{
				cout << courses[i] << endl;
			}
			system("pause");
		}
		else
		{
			system("cls");
			cout << courses[choice - 1] << endl;
			system("pause");
		}
	}
}
		break;
		} if (exitOption3) break;

	} while (true);

}



