#include <iostream>
using namespace std;

// Function to find the maximum profit
int mP(int* value, int n)
{
	int profit = 0, cday = n - 1;

	// Start from the last day
	while (cday > 0) {

		int day = cday - 1;

		// Traverse and keep adding the
		// profit until a day with
		// price of stock higher
		// than currentDay is obtained
		while (day >= 0
			&& (value[cday]
				> value[day])) {

			profit += (value[cday]
					- value[day]);

			day--;
		}

		// Set this day as currentDay
		// with maximum cost of stock
		// currently
		cday = day;
	}

	// Return the profit
	return profit;
}

// Driver Code
int main()
{
	// Given array of prices
	int value[] = { 2, 3, 5 };

	int N = sizeof(value) / sizeof(value[0]);

	// Function Call
	cout << mP(value, N);

	return 0;
}
    