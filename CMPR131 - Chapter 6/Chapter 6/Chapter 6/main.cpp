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
	bool coursesCreated = false;

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
			return;
		}
			break;
		case 1:
		{
			numCourses = inputInteger("\n\t");
		}
			break;
		case 2: 
		{

		}
			break;
		case 3: 
		{

		}
			break;
		case 4: 
		{

		}
			break;
		case 5: 
		{

		}
			break;
		}


	} while (true);
}
