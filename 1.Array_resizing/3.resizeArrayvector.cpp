#include <iostream>
#include <vector>

int main() {
    std::vector<int> dynamicArray;

    // Add elements to the vector
    dynamicArray.push_back(1);
    dynamicArray.push_back(2);
    dynamicArray.push_back(3);

    // Resize the vector
    dynamicArray.resize(5);

    // Add more elements
    dynamicArray.push_back(4);
    dynamicArray.push_back(5);

    // Print elements
    for (const auto& element : dynamicArray) {
        std::cout << element << " ";
    }

    return 0;
}
