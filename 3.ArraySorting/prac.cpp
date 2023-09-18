#include <iostream>
#include <vector>
#include <string>

using namespace std;


void selectionSort(vector<pair<int, string>>& crates) {
    int n = crates.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (crates[j].first < crates[minIndex].first) {
                minIndex = j;
            }
        }
        swap(crates[i], crates[minIndex]);
    }
}
int main() {
    vector<pair<int, string>> crates = {{5, "Crate A"}, {2, "Crate B"}, {8, "Crate C"}, {1, "Crate D"}, {7, "Crate E"}};
    selectionSort(crates);
    for (const auto& crate : crates) {
        cout << crate.second << " to be shipped out in " << crate.first << " days" << endl;
    }
    return 0;
}

// answer is selection sort as it uses least swaps