//Implement Check if it is possible to transform one string to 
another.
Statement Given two strings s1 and s2 (all letters in uppercase). 
Check if it is possible to convert s1 to s2 by performing following 
operations.
1. Make some lowercase letters uppercase.
2. Delete all the lowercase letters.
Input: s1 = daBcd s2 = ABC Output: yes
Input: s1 = argaju s2 = RAJ Output: yes

#include <iostream>
#include <cstring>
using namespace std;

bool convert(string s1, string s2) {
    int a = s1.length();
    int b = s2.length();

    // dp[i][j] will be true if s1[0..i-1] can be transformed to s2[0..j-1]
    bool dp[a + 1][b + 1];
    memset(dp, false, sizeof(dp));

    // Base case: s1 can be transformed to an empty string by deleting all lowercase letters
    dp[0][0] = true;
    for (int i = 1; i <= a; i++) {
        dp[i][0] = dp[i - 1][0] && islower(s1[i - 1]);
    }

    // Fill the dp table
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (toupper(s1[i - 1]) == s2[j - 1]) {
                // Either match the current character (after making it uppercase if necessary)
                // or delete the current character if it's lowercase
                dp[i][j] = dp[i - 1][j - 1] || (islower(s1[i - 1]) && dp[i - 1][j]);
            } else if (islower(s1[i - 1])) {
                // If characters don't match, we can still delete the lowercase character
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Final answer will be in dp[a][b]
    return dp[a][b];
}

int main() {
    string s1 = "daBcd";
    string s2 = "ABC";
    
    if (convert(s1, s2)) {
        cout << "yes" << endl;  // Output: yes
    } else {
        cout << "no" << endl;
    }

    string s3 = "argaju";
    string s4 = "RAJ";
    
    if (convert(s3, s4)) {
        cout << "yes" << endl;  // Output: yes
    } else {
        cout << "no" << endl;
    }

    return 0;
}
