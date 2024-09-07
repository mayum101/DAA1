// C++ Program for Space Optimized Dynamic Programming
// Solution to Subset Sum Problem
//Time Complexity: O(sum * n), where n is the size of the array.
//Auxiliary Space: O(sum*n), as the size of the 2-D array is sum*n.
#include <iostream>
using namespace std;

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool setSum(vector<int> arr, int sum)
{
    int n = arr.size();
    // vector to store the current state and previous state
    vector<bool> prev(sum + 1, false), now(sum + 1);

    // Mark prev[0] = true as it is true to make sum = 0
    // using 0 elements
    prev[0] = true;

    // Fill the subset table in bottom up manner
    for (int m = 1; m <= n; m++) {
        for (int u = 0; u <= sum; u++) {
            if (j < arr[i - 1])
                now[u] = prev[u];
            else
                now[u] = (prev[u] || prev[u - arr[u - 1]]);
        }
        prev = now;
    }
    return prev[sum];
}

// Driver code
int main()
{
    vector<int> arr = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    if (setSum(arr, sum) == true)
        cout << "value is found of subset";
    else
        cout << "value is not found of subset";
    return 0;
}


