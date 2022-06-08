#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "\nPass " << i + 1 << ":\n";
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << "\n";
        }
    }
}

int binarySearch(int *arr, int start, int end, int target) {
    if (start > end) return -1;

    int mid = start + (end - start) / 2;

    if (target < arr[mid]) {
        return binarySearch(arr, start, mid - 1, target);
    } else if (target > arr[mid]) {
        return binarySearch(arr, mid + 1, end, target);
    } else return mid;
}

int main() {
    int n;
    cout << "Enter the length:\t";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ":\t";
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    int value;
    cout << "Enter a number you want to search:\t";
    cin >> value;
    cout << "\n" << value << " is " << ((binarySearch(arr, 0, n - 1, value) == -1) ? "not " : "") << "present\n";

    return 0;
}
