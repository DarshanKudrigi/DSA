// approch for  the binary search is to divide the array into two halves and check if the target element is present in the left half or the right half. If it is present in the left half, we repeat the process on the left half, otherwise we repeat it on the right half. This process continues until we find the target element or the subarray size becomes zero.

// time complexity of binary search is O(log n) where n is the number of elements in the array. This is because with each iteration, we are halving the size of the array we are searching through.

// space complexity of binary search is O(1) as we are using only a constant amount of space for variables like low, high, and mid.

// code:

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
