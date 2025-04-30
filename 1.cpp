#include <iostream>
#include <vector>
using namespace std;

int insertionSort(vector<int>& arr) {
    int comparisons = 0;
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (++comparisons && arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comps = insertionSort(arr);
    for (int num : arr) cout << num << " ";
    cout << "\nComparisons: " << comps << endl;
    return 0;
} 
