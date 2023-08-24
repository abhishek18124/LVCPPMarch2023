/*

    https://leetcode.com/problems/wildcard-matching/

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    // bool helper(string s, string p, int m, int n, int i, int j) {

    //     // base case

    //     if (i == m) {
    //         // check if p[j...n-1] matches s[m...m-1] = ""
    //         bool flag = true; // assume p[j...n-1] is all '*'
    //         for (int k = j; k < n; k++) {
    //             if (p[k] != '*') {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         return flag;
    //     }

    //     if (j == n) { // i != m
    //         // check if p[n...n-1] = "" matches s[i...m-1] (non-empty)
    //         return false;
    //     }

    //     // recursive case

    //     // check if p[j...n-1] matches s[i...m-1]

    //     if (s[i] == p[j]) {
    //         // recursively, check if p[j+1...n-1] matches s[i+1...m-1]
    //         return helper(s, p, m, n, i + 1, j + 1);
    //     } else {
    //         if (p[j] == '?' || p[j] == '*') {

    //             if (p[j] == '?') {
    //                 // recursively, check if p[j+1...n-1] matches s[i+1...m-1]
    //                 return helper(s, p, m, n, i + 1, j + 1);
    //             } else { // p[j] == '*'

    //                 // 1. replace p[j] with ""

    //                 // recursively, check if p[j+1...n-1] matches s[i...m-1]

    //                 bool X = helper(s, p, m, n, i, j + 1);

    //                 // 2. replace p[j] with 1 or more character(s)

    //                 // recursively, check if p[j...n-1] matches s[i+1...m-1]

    //                 bool Y = helper(s, p, m, n, i + 1, j);

    //                 return X or Y;

    //             }

    //         } else { // p[j] is not a wildcard character
    //             return false;
    //         }
    //     }

    // }

    // recursive algorithm

    bool helper(string s, string p, int m, int n, int i, int j) {

        // base case

        if (i == m) {
            // check if p[j...n-1] matches s[m...m-1] = ""
            bool flag = true; // assume p[j...n-1] is all '*'
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            return flag;
        }

        if (j == n) { // i != m
            // check if p[n...n-1] = "" matches s[i...m-1] (non-empty)
            return false;
        }

        // recursive case

        // check if p[j...n-1] matches s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {
            // recursively, check if p[j+1...n-1] matches s[i+1...m-1]
            return helper(s, p, m, n, i + 1, j + 1);
        } else if (p[j] == '*') {

            // 1. replace p[j] with ""

            // recursively, check if p[j+1...n-1] matches s[i...m-1]

            // 2. replace p[j] with 1 or more character(s)

            // recursively, check if p[j...n-1] matches s[i+1...m-1]

            return helper(s, p, m, n, i, j + 1) or helper(s, p, m, n, i + 1, j);

        } else { // p[j] is not a wildcard character
            return false;
        }
    }

    bool helperTopDown(string s, string p, int m, int n, int i, int j, vector<vector<int>>& dp) {

        // lookup
        if (dp[i][j] != 2) {
            return dp[i][j];
        }

        // base case

        if (i == m) {
            // check if p[j...n-1] matches s[m...m-1] = ""
            bool flag = true; // assume p[j...n-1] is all '*'
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            return dp[i][j] = flag;
        }

        if (j == n) { // i != m
            // check if p[n...n-1] = "" matches s[i...m-1] (non-empty)
            return dp[i][j] = false;
        }

        // recursive case

        // check if p[j...n-1] matches s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {
            // recursively, check if p[j+1...n-1] matches s[i+1...m-1]
            return dp[i][j] = helperTopDown(s, p, m, n, i + 1, j + 1, dp);
        } else if (p[j] == '*') {

            // 1. replace p[j] with ""

            // recursively, check if p[j+1...n-1] matches s[i...m-1]

            // 2. replace p[j] with 1 or more character(s)

            // recursively, check if p[j...n-1] matches s[i+1...m-1]

            return dp[i][j] = helperTopDown(s, p, m, n, i, j + 1, dp) or helperTopDown(s, p, m, n, i + 1, j, dp);

        } else { // p[j] is not a wildcard character
            return dp[i][j] = false;
        }
    }

    bool helperBottomUp(string s, string p, int m, int n) {

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        for (int j = 0; j <= n; j++) {

            // i == m

            // check if p[j...n-1] matches s[m...m-1] = ""

            bool flag = true; // assume p[j...n-1] contains only stars
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            dp[m][j] = flag;
        }

        for (int i = 0; i < m; i++) {

            // j == n

            // check if p[n...n-1] = "" matches s[i...m-1]

            dp[i][n] = false;
        }

        // dp[m][n] = true; // do this if previous loop runs froom i=0 to <=m

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // check if p[j...n-1] matches s[i...m-1]

                if (s[i] == p[j] || p[j] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (p[j] == '*') {
                    dp[i][j] = dp[i][j + 1] or dp[i + 1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0]; // at the (0, 0)th index of dp[][], we store f(0, 0)

    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // return helper(s, p, m, n, 0, 0);
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 2));
        // return helperTopDown(s, p, m, n, 0, 0, dp);
        return helperBottomUp(s, p, m, n);
    }
};