#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n);
    int count[maxVal + 1] = {0};

    for (int i = 0; i < n; i++) count[arr[i]]++;
    int index = 0;
    for (int i = 0; i <= maxVal; i++)
        while (count[i]--) arr[index++] = i;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1}, n = 7;
    countingSort(arr, n);
    cout << "Sorted: ";
    for (int i : arr) cout << i << " ";
    return 0;
}
