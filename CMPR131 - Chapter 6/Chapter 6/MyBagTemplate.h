#pragma once
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class MyBagTemplate
{
private:
    T* bag;
    int size;
    int capacity;

public:
    MyBagTemplate()
    {
        bag = nullptr;
        size = 0;
        capacity = 0;
    }

    ~MyBagTemplate()
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

    void insert(const T& value)
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
        T* temp = new T[capacity * 2];
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
        if (bag == nullptr)
        {
            string exceptionString = "\n\t\tMyBag is empty.\n\n";
            throw exceptionString;
        }

        delete[] bag;
        bag = nullptr;
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
        if (index < 0 || index >= size)
            return;

        for (int i = index; i < size - 1; i++)
        {
            bag[i] = bag[i + 1];
        }

        size--;

        if (size == (capacity / 2))
        {
            shrinkBag();
        }
    }

    void shrinkBag()
    {
        capacity = size;
        T* temp = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            temp[i] = bag[i];
        }

        delete[] bag;
        bag = temp;
    }

    int linearSearch(const T& value) const
    {
        for (int i = 0; i < size; i++)
        {
            if (bag[i] == value)
                return i;
        }
        return -1;
    }

    T operator[](int index) const
    {
        return bag[index];
    }

    // Friend function for output
    friend ostream& operator<<(ostream& output, const MyBagTemplate<T>& b)
    {
        if (b.size == 0)
        {
            string exceptionString = "\n\t\tMyBag is empty.\n\n";
            throw exceptionString;
        }
        else
        {
            output << "\n\t\tMybag contains these sorted items:";
            for (int i = 0; i < b.size; i++)
                output << "\n\t\t[" << i << "] - " << b.bag[i];
        }

        output << "\n";
        return output;
    }
};
