//Divide and Conquer-3
/*Implement a problem of smallest number with at least n
trailing zeroes in factorial.
Statement: Given a number n. The task is to find the smallest
number whose factorial contains at least n trailing zeroes.
Input : n = 1 Output : 5
Input : n = 6 Output : 25

*/



#include <iostream>
using namespace std;

// Function to count the number of trailing zeros in the factorial of a given number
int cntZeros(int n) {
    int cnt = 0;
    // Divide the number by 5 repeatedly to count the factors of 5
    while (n >= 5) {
        n /= 5;
        cnt += n;
    }
    return cnt;
}

// Function to find the smallest number whose factorial has at least 'z' trailing zeros
int Min(int z) {
    if (z == 0) return 0; // Special case: If no trailing zeros are needed, return 0

    int low = 0, high = 5 * z; // Initial range for binary search

    // Perform binary search to find the smallest number with at least 'z' trailing zeros
    while (low < high) {
        int mid = (low + high) / 2;
        // Check if the number of trailing zeros in mid! is less than required
        if (cntZeros(mid) < z) {
            low = mid + 1; // Search in the upper half
        } else {
            high = mid; // Search in the lower half
        }
    }
    return low; // 'low' is the smallest number with at least 'z' trailing zeros
}

int main() {
    int z;
    cout << "Enter the number of trailing zeros required: ";
    cin >> z;

    // Find and output the smallest number whose factorial has at least 'z' trailing zeros
    int result = Min(z);
    cout << "The smallest number whose factorial has at least " << z << " trailing zeros is: " << result << endl;

    return 0;
}