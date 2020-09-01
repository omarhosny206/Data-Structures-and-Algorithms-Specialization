//Time Complexity: O(m x n)
//Auxiliary Space: O(m)
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

void editDistance(string String1, string String2)
{
    int String1_Length = String1.size();
    int String2_Length = String2.size();

    // Create a DP array to memoize result of previous computations
    int DP[2][String1_Length + 1];

    // To fill the DP array with 0
    memset(DP, 0, sizeof DP);

    // Base condition when second string is empty then we remove all characters
    for (int i = 0; i <= String1_Length; i++)
        DP[0][i] = i;

    // Start filling the DP
    for (int i = 1; i <= String2_Length; i++)
    {
        // This loop compares the char from second string with first string characters
        for (int j = 0; j <= String1_Length; j++)
        {
            // if first string is empty then we have to perform add character operation to get second string
            if (j == 0)
                DP[i % 2][j] = i;

            // if character from both string is same then we do not perform any operation (Match) . here i % 2 is for bound the row number.
            else if (String1[j - 1] == String2[i - 1])
            {
                DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
            }

            // if character from both string is not same then we take the minimum from three specified operation (Insert, Remove, Replace)
            else
            {
                DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j], min(DP[i % 2][j - 1], DP[(i - 1) % 2][j - 1]));
            }
        }
    }

    cout << DP[String2_Length % 2][String1_Length] << endl;
}

int main()
{
    string String1 = "food";
    string String2 = "money";
    // Replace, Match, Replace, Replace, insert = 1 + 0 + 1 + 1 + 1 = 4 //
    editDistance(String1, String2);

    string String3 = "saturday";
    string String4 = "sunday";
    editDistance(String3, String4);
    return 0;
}
