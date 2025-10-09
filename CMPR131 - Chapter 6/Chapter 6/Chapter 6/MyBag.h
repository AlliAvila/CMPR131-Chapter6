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
	//Constructor
	MyBag()
	{
		capacity = 3;
		size = 0;
		bag = new int[capacity];
	}

	//Destructor
	~MyBag()
	{
		delete[] bag;
	}

	//Precondition: N/A
	//Postcondition: Return the current number of elements in the bag
	int getSize() const
	{
		return size;
	}
		
	//Precondition: N/A
	//Postcondition: Return the current capacity of the bag
	int getCapacity() const
	{
		return capacity;
	}

	//Precondition: N/A
	//Postcondition: Insert a new integer into the bag; grow the bag if full
	void insert(int value)
	{
		if (size == capacity)
		{
			growBag();
		}

		bag[size] = value;

		size++;
	}

	//Precondition: N/A
	//Postcondition: Double the capacity of the bag when full
	void growBag()
	{
		int newCapacity;

		if (capacity != 0)
		{
			newCapacity = capacity * 2;
		}
		else
		{
			newCapacity = 3;
		}

		int* temp = new int[newCapacity];

		for (int i = 0; i < size; i++)
		{
			temp[i] = bag[i];
		}

		delete[] bag;
		bag = temp;
		capacity = newCapacity;
	}

	//Precondition: N/A
	//Postcondition: Clear all elements from the bag and reset size and capacity
	void clear()
	{
		delete[] bag;
		size = 0;
		capacity = 3;
		bag = new int[capacity];
		cout << "\n\t\tMyBag is cleared of all elements.\n";
	}

	//Precondition: N/A
	//Postcondition: Sort the elements in the bag in ascending order
	void sortBag()
	{
		sort(bag, bag + size);
		cout << "\n\tMyBag has been sorted.\n\n";
	}

	//Precondition: index is within the range of 0 to size-1
	//Postcondition: Remove the element at the specified index and shift remaining elements left; shrink capacity if necessary
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

	//Precondition: N/A
	//Postcondition: Reduce the capacity of the bag to match the current size
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

	//Precondition: N/A
	//Postcondition: Linear search to find the index of a value in the bag; returns -1 if not found
	int linearSearch(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (bag[i] == value)
				return i;
		}

		return -1;
	}

	//Precondition: index is within the range of 0 to size-1
	//Postcondition: Overloaded subscript operator to access elements in the bag
	int operator[](int index) const
	{
		return bag[index];
	}

	//Friend function prototype
	friend ostream& operator << (ostream& output, const MyBag& bag);

};

//Precondition: N/A
//Postcondition: Overloaded output operator for MyBag class
ostream& operator << (ostream& output, const MyBag& bag)
{
		output << "\n\t\tMyBag contains these sorted integers:";
		for (int i = 0; i < bag.size; i++)
			output << "\n\t\t[" + to_string(i) + "] - " + to_string(bag[i]);
	output << "\n";

	return output;

}
