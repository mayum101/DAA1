//Divide and Conquer-2
/*Implement a problem of move all zeroes to end of array.
Statement: Given an array of random numbers, Push all the zero’s
of a given array to the end of the array. For example, if the given
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1,
9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be
same.
Input : arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};

*/
#include <iostream>
using namespace std;

void shiftZToEnd(int num[], int low, int high) {
    if (low >= high) return;

    // Divide: Find the mid-point of the array
    int mid = (low + high) / 2;

    // Conquer: Recursively move zeroes in the left and right halves
    shiftZToEnd(num, low, mid);
    shiftZToEnd(num, mid + 1, high);

    // Combine: Merge the two halves
    int tempArray[high - low + 1];
    int leftIndex = low, rightIndex = mid + 1, tempIndex = 0;

    // Copy non-zero elements from left half
    while (leftIndex <= mid) {
        if (num[leftIndex] != 0) {
            tempArray[tempIndex++] = num[leftIndex];
        }
        leftIndex++;
    }

    // Copy non-zero elements from right half
    while (rightIndex <= high) {
        if (num[rightIndex] != 0) {
            tempArray[tempIndex++] = num[rightIndex];
        }
        rightIndex++;
    }

    // Fill the remaining positions with zeroes
    while (tempIndex < (high - low + 1)) {
        tempArray[tempIndex++] = 0;
    }

    // Copy the merged elements back to the original array
    for (int i = low; i <= high; i++) {
        num[i] = tempArray[i - low];
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int num[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> num[i];
    }

    shiftZToEnd(num, 0, size - 1);

    // Print the result
    cout << "Array after moving zeroes to the end: ";
    for (int i = 0; i < size; i++) {
        cout << num[i] << " ";
    }

    return 0;
}