#include <iostream>

using namespace std;

class Sorting {
private:
    int* arr;
    int size;
    bool isSortedFlag;

public:
    Sorting(int* inputArr, int n) {
        arr = new int[n];
        size = n;
        isSortedFlag = false;

        for (int i = 0; i < n; i++) {
            arr[i] = inputArr[i];
        }
    }
    ~Sorting() {
        delete[] arr;
    }
    void bubbleSort() {
        if (!isSortedFlag) {
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            isSortedFlag = true;
        }
    }
    bool isSorted() {
        return isSortedFlag;
    }
    void displayArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int inputArr[] = {3, 4, 2, 1, 8, 9, 7, 6, 5};
    int n = sizeof(inputArr) / sizeof(inputArr[0]);

    Sorting sortingObj(inputArr, n);

    cout << "Original Array: ";
    sortingObj.displayArray();

    if (!sortingObj.isSorted()) {
        sortingObj.bubbleSort();
        cout << "Sorted Array: ";
        sortingObj.displayArray();
    } else {
        cout << "Array is already sorted." << endl;
    }

    return 0;
}
