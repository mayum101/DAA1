//Implement Coin Change problem.
//Statement Given an integer array of coins[ ] of size N representing 
//different types of currency and an integer sum, The task is to find 
//the number of ways to make sum by using different combinations 
//from coins[]. 
//Note: Assume that you have an infinite supply of each type of 
//coin.
//Input: sum = 4, coins[] = {1,2,3}, Output: 4
//Input: sum = 10, coins[] = {2, 5, 3, 6} Output: 5

#include <iostream>
using namespace std;

int countWays(int coins[], int n, int sum) {
    // Create a dp array to store the number of ways to make each value from 0 to sum
    int dp[sum + 1] = {0};
    
    // Base case: There's one way to make the sum 0 (by selecting no coins)
    dp[0] = 1;

    // Iterate over each coin
    for (int i = 0; i < n; i++) {
        // For each coin, update the dp array from coin value to sum
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    // Return the number of ways to make the given sum
    return dp[sum];
}

int main() {
    int coins1[] = {1, 2, 3};
    int sum1 = 4;
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    cout << "Number of ways to make sum " << sum1 << " = " << countWays(coins1, n1, sum1) << endl; // Output: 4

    int coins2[] = {2, 5, 3, 6};
    int sum2 = 10;
    int n2 = sizeof(coins2) / sizeof(coins2[0]);
    cout << "Number of ways to make sum " << sum2 << " = " << countWays(coins2, n2, sum2) << endl; // Output: 5

    return 0;
}