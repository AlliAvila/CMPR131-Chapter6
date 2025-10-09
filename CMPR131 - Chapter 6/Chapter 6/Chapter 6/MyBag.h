#pragma once
#include <algorithm>
#include <iostream>

class MyBag
{
private:
	int* bag;
	int size;
	int capacity;
public:
	MyBag()
	{
		capacity = 3;
		size = 0;
		bag = new int [capacity];
	}
	~MyBag()
	{
		delete[] bag;
	}
	int getSize() const
	{
		return size;
	}
	int getCapacity() const
	{
		return capacity;
	}
	void insert(int value)
	{
		if (size == capacity)
		{
			growBag();
		}

		bag[size] = value;

		size++;
	}
	void growBag()
	{
		int* temp = new int[capacity * 2];

		capacity *= 2;

		for (int i = 0; i < size; i++)
		{
			temp[i] = bag[i];
		}

		delete[] bag;

		bag = temp;

	}
	void clear()
	{
		delete[] bag;
		size = 0;
		capacity = 3;
		bag = new int[capacity];
		cout << "\n\t\tMyBag is cleared of all elements.\n";
	}

	void sortBag()
	{
		sort(bag, bag + size);
		cout << "\n\tMybag has been sorted.\n\n";
	}
	void remove(int index)
	{
		for (int i = 0; i < size; i++)
		{
			bag[i] = bag[i++];
		}

		bag[size - 1] = 0;

		size--;


		if (size == (capacity / 2))
		{
			shrinkBag();

		}

	}
	void shrinkBag()
	{
		capacity = size;

		int* temp = new int[capacity];

		for (int i = 0; i < size; i++)
		{
			temp[i] = bag[i];
		}

		delete[] bag;

		bag = temp;

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

	friend ostream& operator << (ostream& output, const MyBag& bag);

};

ostream& operator << (ostream& output,const MyBag& bag)
{
	if (bag.size == 0)
	{
		string exceptionString = "\n\t\tMyBag is empty.\n\n";
		throw exceptionString;
	}
	else
	{
		output << "\n\t\tMybag contains these sorted integers:";
		for (int i = 0; i < bag.size; i++)
			output << "\n\t\t[" + to_string(i) + "] - " + to_string(bag[i]);
	}

	output << "\n";

	return output;

}
