#pragma once
#include <algorithm>

class MyBag
{
private:
	int* bag;
	int size;
	int capacity;
public:
	MyBag()
	{
		bag = nullptr;
		size = 0;
		capacity = 0;
	}
	~MyBag()
	{
		delete[] bag;
	}
	int getSize() const
	{
		return size;
	}
	void insert(int value)
	{
		int* newArray = new int[size + 1];
		
		for (int i = 0; i < size; i++)
		{
			newArray[i] = bag[i];
		}

		size++;
		delete[] bag;

		bag = newArray;
		bag[size - 1] = value;

	}
	void display()
	{
		if (size == 0)
		{
			string exceptionString = "\n\t\tMyBag is empty.\n\n";
			throw exceptionString;
		}
		else
		{
			cout << "\n\t\tMybag contains these sorted integers:";
			for (int i = 0; i < size; i++)
				cout << "\n\t\t[" + to_string(i) + "] - " + to_string(bag[i]);
		}

		cout << "\n";
	}
	void clear()
	{
		if (bag == nullptr)
		{
			string exceptionString = "\n\t\tMyBag is empty.\n\n";
			throw exceptionString;
		}

		delete bag;
		size = 0;
		capacity = 0;
	}
	void sortBag()
	{
		sort(bag, bag + size);
		cout << "\n\tMybag has been sorted.\n\n";
	}
	void remove(int index)
	{
		
		int* TempArray = new int[size - 1];
		int newIndex = 0;


		//copying elements into new array except for deleted one
		for (int i = 0; i < size; i++)
		{
			if (i != index) //this is what skips over the deleted element, will copy everything else into new array
				TempArray[newIndex++] = bag[i];
		}

		delete[] bag;
		bag = TempArray;
		size -= 1;  

	}
	int linearSearch(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (bag[i] == value)
				return i;
		}

		return -1;
	}
	int operator[](int index) const
	{
		return bag[index];
	}

};

