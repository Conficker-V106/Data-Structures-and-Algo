#include <iostream>

using namespace std;

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;
    if (numStudents <= 0){
        cout << "Invalid Size ; \ncondition : (number of students > 0)\n";
        return 1;
    }

    int** examScores = new int*[numStudents];
    int* numTests = new int[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter the number of tests for student " << i + 1 << ": ";
        cin >> numTests[i];

        examScores[i] = new int[numTests[i]];

        for (int j = 0; j < numTests[i]; ++j) {
            cout << "Enter score for student " << i + 1 << ", test " << j + 1 << ": ";
            cin >> examScores[i][j];
        }
    }

    cout << "\nAverage scores:\n";

    for (int i = 0; i < numStudents; ++i) {
        int totalScore = 0;

        for (int j = 0; j < numTests[i]; ++j) {
            totalScore += examScores[i][j];
        }

        double averageScore = static_cast<double>(totalScore) / numTests[i];
        if(averageScore > 0){
            cout << "Student " << i + 1 << ": " << averageScore << "\n";
        }else{
            cout << "Student " << i + 1 << ": " << "Did not Appear in any test\n";
        }
    }

    for (int i = 0; i < numStudents; ++i) {
        delete[] examScores[i];
    }
    delete[] examScores;
    delete[] numTests;

    return 0;
}
