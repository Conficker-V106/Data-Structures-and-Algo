#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
   

    int numRows;

    cout << "Enter the number of rows: ";
    cin >> numRows;
    if (numRows <= 0){
        cout << "Invalid Size ; \ncondition : (number of rows > 0)\n";
        return 1;
    }
    int **array = new int *[numRows];
    int *sizeOfRows = new int[numRows];

    for (int i = 0; i < numRows; i++) {
        cout << "Enter the columns for row " << i + 1 << ": ";
        cin >> sizeOfRows[i];
        if (sizeOfRows[i] <= 0){
            cout << "Invalid Size ; \ncondition : (number of columns > 0)\n";
            return 1;
        }
        array[i] = new int[sizeOfRows[i]];
        for (int j = 0; j < sizeOfRows[i]; j++) {
            array[i][j] = rand() % 100 + 1; 
        }
    }
    cout << "New Array:" << endl;
    for (int i = 0; i < numRows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < sizeOfRows[i]; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < numRows; i++) {
        delete[] array[i]; 
    }
    delete[] array; 
    delete[] sizeOfRows; 

    return 0;
}

