#include <iostream>

int main() {
    int size = 5;
    int* oldArray = new int[size];  // Create initial array

    // Initialize the old array with some values
    for (int i = 0; i < size; ++i) {
        oldArray[i] = i + 1;
    }

    int newSize = 4;
    int* newArray = new int[newSize];  // Create a new array with the desired size
    int indexToRemove = 2;
    // Copy elements from the old array to the new array
    for (int i = 0; i < size; ++i) {
        if(i<indexToRemove){    
            newArray[i] = oldArray[i];
        }else{
            newArray[i] = oldArray[i+1];
        }
    }

    // Clean up the old array
    delete[] oldArray;

    // Update the pointer to point to the new array
    oldArray = newArray;

    // Print elements
    for (int i = 0; i < newSize; ++i) {
        std::cout << oldArray[i] << " ";
    }

    // Clean up the new array
    delete[] oldArray;

    return 0;
}
