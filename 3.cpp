#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i, int& comparisons) {
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && (++comparisons && arr[l] > arr[largest])) largest = l;
    if (r < n && (++comparisons && arr[r] > arr[largest])) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}

int heapSort(vector<int>& arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, comparisons);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons);
    }
    return comparisons;
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comps = heapSort(arr);
    for (int num : arr) cout << num << " ";
    cout << "\nComparisons: " << comps << endl;
    return 0;
}
