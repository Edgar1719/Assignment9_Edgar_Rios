#include <iostream>
#include "generic_array.h"

int main()
{
    // Create an integer array
    GenericArray<int> int_array;

    // Add 12 elements to the array
    for(int i = 0; i < 12; i++)
    {
        int_array.addElement(i * 2);
    }

    std::cout << "Integer array:" << std::endl;

    std::cout << "Size: "
              << int_array.size() << std::endl;

    std::cout << "Element at index 3: "
              << int_array.at(3) << std::endl;

    std::cout << "Sum: "
              << int_array.sum() << std::endl;

    std::cout << "Maximum: "
              << int_array.max() << std::endl;

    std::cout << "Minimum: "
              << int_array.min() << std::endl;

    // Get a separate array containing indices 5 to 10
    int *sliced_array = int_array.slice(5, 10);

    if(sliced_array != nullptr)
    {
        std::cout << "Slice from 5 to 10: ";

        for(int i = 0; i < 6; i++)
        {
            std::cout << sliced_array[i] << " ";
        }

        std::cout << std::endl;

        // Free the separate sliced array
        delete[] sliced_array;
    }

    // Test the template with double values
    GenericArray<double> double_array;

    double_array.addElement(1.5);
    double_array.addElement(2.5);
    double_array.addElement(3.5);

    std::cout << "\nDouble array:" << std::endl;

    std::cout << "Size: "
              << double_array.size() << std::endl;

    std::cout << "Sum: "
              << double_array.sum() << std::endl;

    std::cout << "Maximum: "
              << double_array.max() << std::endl;

    std::cout << "Minimum: "
              << double_array.min() << std::endl;

    return 0;
}

