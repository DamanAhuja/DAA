#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int l, int m, int r, int& comparisons) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    return comparisons;
}

int mergeSort(vector<int>& arr, int l, int r, int& comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);
        merge(arr, l, m, r, comparisons);
    }
    return comparisons;
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    int comps = 0;
    mergeSort(arr, 0, arr.size() - 1, comps);
    for (int num : arr) cout << num << " ";
    cout << "\nComparisons: " << comps << endl;
    return 0;
} 
