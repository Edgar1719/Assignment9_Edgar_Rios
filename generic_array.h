#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include <iostream>

template <typename T>
class GenericArray
{
private:
    T *values;
    int array_size;

public:

    // Default constructor
    GenericArray()
    {
        values = nullptr;
        array_size = 0;
    }

    // Destructor
    ~GenericArray()
    {
        delete[] values;
    }

    // Add an element to the end of the array
    void addElement(T new_value)
    {
        T *new_array = new T[array_size + 1];

        for(int i = 0; i < array_size; i++)
        {
            new_array[i] = values[i];
        }

        new_array[array_size] = new_value;

        delete[] values;
        values = new_array;
        array_size++;
    }

    // Return the element at a given index
    T at(int index)
    {
        if(index < 0 || index >= array_size)
        {
            std::cout << "Index out of bounds." << std::endl;
            return 0;
        }

        return values[index];
    }

    // Return the size of the array
    int size()
    {
        return array_size;
    }

    // Return the sum of all elements
    T sum()
    {
        T total = 0;

        for(int i = 0; i < array_size; i++)
        {
            total += values[i];
        }

        return total;
    }

    // Find the maximum value
    T max()
    {
        if(array_size == 0)
        {
            std::cout << "Array is empty." << std::endl;
            return 0;
        }

        T largest = values[0];

        for(int i = 1; i < array_size; i++)
        {
            if(values[i] > largest)
                largest = values[i];
        }

        return largest;
    }

    // Find the minimum value
    T min()
    {
        if(array_size == 0)
        {
            std::cout << "Array is empty." << std::endl;
            return 0;
        }

        T smallest = values[0];

        for(int i = 1; i < array_size; i++)
        {
            if(values[i] < smallest)
                smallest = values[i];
        }

        return smallest;
    }

    // Create a new array from begin to end
    T *slice(int begin, int end)
    {
        if(begin < 1 || end >= array_size || begin > end)
        {
            std::cout << "Invalid slice bounds." << std::endl;
            return nullptr;
        }

        int slice_size = end - begin + 1;
        T *new_array = new T[slice_size];

        for(int i = 0; i < slice_size; i++)
        {
            new_array[i] = values[begin + i];
        }

        return new_array;
    }
};

#endif

