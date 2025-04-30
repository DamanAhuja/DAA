#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int& comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comps = 0;
    quickSort(arr, 0, arr.size() - 1, comps);
    for (int num : arr) cout << num << " ";
    cout << "\nComparisons: " << comps << endl;
    return 0;
}

