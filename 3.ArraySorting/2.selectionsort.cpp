#include <iostream>
#include <vector>
#include <string>

using namespace std;

class OfficeLayout {
private:
    vector<pair<string, int>> desks;

public:
    OfficeLayout(vector<pair<string, int>> inputDesks) {
        desks = inputDesks;
    }

    void insertionSort() {
        for (int i = 1; i < desks.size(); i++) {
            pair<string, int> currentDesk = desks[i];
            int j = i - 1;

            while (j >= 0 && currentDesk.second < desks[j].second) {
                desks[j + 1] = desks[j];
                j--;
            }

            desks[j + 1] = currentDesk;
        }
    }

    void displaySortedLayout() {
        for (const auto& desk : desks) {
            cout << desk.first << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<pair<string, int>> desks = {
        {"Employee", 6},
        {"CFO", 3},
        {"Manager", 5},
        {"Employee", 6},
        {"VP", 4},
        {"CTO", 2},
        {"Manager", 5},
        {"CEO", 1}
    };

    OfficeLayout layout(desks);

    cout << "Initial Office Layout:" << endl;
    layout.displaySortedLayout();

    layout.insertionSort();

    cout << "\nSorted Office Layout:" << endl;
    layout.displaySortedLayout();

    return 0;
}
