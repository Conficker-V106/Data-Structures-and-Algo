#include <iostream>

using namespace std;

class DateSorter {
public:
    void selectionSort(int dates[][3], int size) {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (dates[j][2] < dates[minIndex][2] ||
                    (dates[j][2] == dates[minIndex][2] && dates[j][1] < dates[minIndex][1]) ||
                    (dates[j][2] == dates[minIndex][2] && dates[j][1] == dates[minIndex][1] && dates[j][0] < dates[minIndex][0])) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swapDates(dates[i], dates[minIndex]);
            }
        }
    }

    void swapDates(int date1[3], int date2[3]) {
        int temp[3];
        for (int i = 0; i < 3; i++) {
            temp[i] = date1[i];
            date1[i] = date2[i];
            date2[i] = temp[i];
        }
    }
};

int main() {
    int dates[5][3];

    DateSorter dateSorter;

    cout << "Enter 5 dates (day, month, and year):" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> dates[i][0] >> dates[i][1] >> dates[i][2];
    }

    dateSorter.selectionSort(dates, 5);

    cout << "Sorted Dates:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << dates[i][0] << "/" << dates[i][1] << "/" << dates[i][2] << endl;
    }

    return 0;
}
