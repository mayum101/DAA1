#include <iostream>
#include <algorithm>
using namespace std;

// Function to sort shops based on end time
void sortShops(int S[], int E[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (E[j] > E[j + 1]) {
                // Swap end times
                swap(E[j], E[j + 1]);
                // Swap corresponding start times
                swap(S[j], S[j + 1]);
            }
        }
    }
}

int maxShopsVisited(int S[], int E[], int N, int K) {
    // Sort the shops by their end time
    sortShops(S, E, N);
    
    int persons[100] = {0}; // To store when each person is free
    int totalShops = 0;     // Count of total shops visited

    // Try to assign each shop to one of the K persons
 for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (persons[j] <= S[i]) {  // If person j is free before shop starts
                persons[j] = E[i];     // Assign this shop to person j
                totalShops++;          // Count this shop
                break;                 // Move to the next shop
            }
        }
    }

    return totalShops;
}

int main() {
    int S1[] = {1, 8, 3, 2, 6}; // Start times
    int E1[] = {5, 10, 6, 5, 9}; // End times
    int N1 = sizeof(S1) / sizeof(S1[0]);
    int K1 = 2; // Number of people
    cout << "Maximum shops visited: " << maxShopsVisited(S1, E1, N1, K1) << endl; // Output: 4

    int S2[] = {1, 2, 3};
    int E2[] = {3, 4, 5};
    int N2 = sizeof(S2) / sizeof(S2[0]);
    int K2 = 2;
    cout << "Maximum shops visited: " << maxShopsVisited(S2, E2, N2, K2) << endl; // Output: 3

    return 0;
}