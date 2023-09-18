# include <iostream>

using namespace std;

void MinMax(int *arr_, int size_, int *min_, int *max_) {
    *min_ = *max_ = arr_[0];
    for (int i = 1; i < size_; i++) {
        if (arr_[i] < *min_) {
            *min_ = arr_[i];
        }
        if (arr_[i] > *max_) {
            *max_ = arr_[i]; 
        }
    }
}
int main() {
    int size;
    cout << "Enter Size of Array: " ; cin >> size ;
    if (size <= 0){
        cout << "Invalid Size ; \ncondition : (size > 0)\n";
        return 1;
    }
    int* array = new int[size];
    for(int i = 0; i < size; i++){
        cout << "Enter Value For Index" << i << ": "; cin >> array[i] ;
    }
    int min, max;
    MinMax(array, size, &min, &max);
    cout << "Smallest element:" << min << "\n" ;
    cout << "Smallest element:" << max << "\n" ;
    return 0;
}