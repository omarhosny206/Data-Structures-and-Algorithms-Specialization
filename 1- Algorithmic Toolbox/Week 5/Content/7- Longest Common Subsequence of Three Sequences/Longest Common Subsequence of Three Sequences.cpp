#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// Function to return maximum of three integers
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

// Function to find length of Longest Common Subsequence of
// sequences X[0..m-1], Y[0..n-1] and Z[0..o-1]
int LCS(string String1, string String2, string String3, int String1_Length, int String2_Length, int String3_Length, auto &Lookup)
{
    // return if we have reached the end of either sequence
    if (String1_Length == 0 || String2_Length == 0 || String3_Length == 0)
        return 0;

    // construct an unique map key from dynamic elements of the input
    string Key = to_string(String1_Length) + "|" + to_string(String2_Length) + "|" + to_string(String3_Length);

    // if sub-problem is seen for the first time, solve it and store its result in a map
    if (Lookup.find(Key) == Lookup.end())
    {
        // if last character of X, Y, Z matches
        if (String1[String1_Length - 1] == String2[String2_Length - 1] && String2[String2_Length - 1] == String3[String3_Length - 1])
            Lookup[Key] = LCS(String1, String2, String3, String1_Length - 1, String2_Length - 1, String3_Length - 1, Lookup) + 1;
        else
            // else if last character of X, Y, Z don't match
            Lookup[Key] = max(LCS(String1, String2, String3, String1_Length - 1, String2_Length, String3_Length, Lookup),
                              LCS(String1, String2, String3, String1_Length, String2_Length - 1, String3_Length, Lookup),
                              LCS(String1, String2, String3, String1_Length, String2_Length, String3_Length - 1, Lookup));
    }
    // return the subproblem solution from the map
    return Lookup[Key];
}

// Longest Common Subsequence of K-sequences
int main()
{
    string String1 = "ABCBDAB", String2 = "BDCABA", String3 = "BADACB";

    // create a map to store solutions of subproblems
    unordered_map<string, int> Lookup;

    cout << LCS(String1, String2, String3, String1.length(), String2.length(), String3.length(), Lookup);

    return 0;
}