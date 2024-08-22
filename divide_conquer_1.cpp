//Divide and Conquer-1
/*Implement a problem of number of zeroes.
Statement: Given an array of 1s and 0s which has all 1s first
followed by all 0s? Find the number of 0s. Count the number of
zeroes in the given array.
Input: arr[] = {1, 1, 1, 1, 0, 0} Output: 2
Input: arr[] = {1, 0, 0, 0, 0} Output: 4

*/
#include <iostream>
using namespace std;

int cntZero(int arr[], int size) {
    int low = 0;
    int high = size - 1;

    // Binary search to find the first occurrence of 0
    while (low <= high) {
        int middle = (low + high) / 2;

        // Check if middle is the first occurrence of 0
        if (arr[middle] == 0 && (middle == 0 || arr[middle - 1] == 1)) {
            return size - middle;
        }
        // If the middle element is 1, search in the right half
        else if (arr[middle] == 1) {
            low = middle + 1;
        }
        // If the middle element is 0 but not the first occurrence, search in the left half
        else {
            high = middle - 1;
        }
    }
    
    // If there are no 0s in the array
    return 0;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int array[n];
    cout << "Enter the elements of the array (only 1s and 0s): ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "Number of 0s: " << cntZero(array, n) << endl;
    
    return 0;
}