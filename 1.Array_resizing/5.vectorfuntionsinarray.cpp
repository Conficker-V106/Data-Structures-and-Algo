#include <iostream>
#include <vector>

int main() {
    // Declare a vector to store integers
    std::vector<int> myVector;

    // Add elements to the vector using push_back()
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Accessing elements using indexing
    std::cout << "First element: " << myVector[0] << std::endl;
    std::cout << "Second element: " << myVector[1] << std::endl;
    std::cout << "Third element: " << myVector[2] << std::endl;

    // Getting the size of the vector
    std::cout << "Vector size: " << myVector.size() << std::endl;

    // Iterating through the vector using a for loop
    std::cout << "Elements in the vector: ";
    for (size_t i = 0; i < myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    // Using iterators to iterate through the vector
    std::cout << "Elements using iterators: ";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Clearing the vector
    myVector.clear();

    // Checking if the vector is empty
    if (myVector.empty()) {
        std::cout << "Vector is empty." << std::endl;
    }

    return 0;
}
