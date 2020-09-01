//Time Complexity: O(m x n)
//Auxiliary Space: O(m x n)
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistance(string String1, string String2, int String1_Length, int String2_Length)
{

    // Create a DP array to memoize result of previous computations
    int DP[String1_Length + 1][String2_Length + 1];

    // Fill DP[][] in bottom up manner
    for (int i = 0; i <= String1_Length; i++)
    {
        // This loop compares the char from String2 with String1 characters
        for (int j = 0; j <= String2_Length; j++)
        {
            // If String1 is empty, only option is to insert all characters of String2
            if (i == 0)
                DP[i][j] = j;

            // If String2 is empty, only option is to remove all characters of String2
            else if (j == 0)
                DP[i][j] = i;

            // if character from both Strings is same then we do not perform any operation (Match)
            else if (String1[i - 1] == String2[j - 1])
                DP[i][j] = DP[i - 1][j - 1];

            // if character from both Strings is not same then we take the minimum from three specified operations (Insert, Remove, Replace)
            else
                DP[i][j] = 1 + min(DP[i][j - 1], min(DP[i - 1][j], DP[i - 1][j - 1]));
        }
    }

    return DP[String1_Length][String2_Length];
}

int main()
{
    string String1 = "food";
    string String2 = "money";
    // Replace, Match, Replace, Replace, insert = 1 + 0 + 1 + 1 + 1 = 4 //
    cout << editDistance(String1, String2, String1.length(), String2.length());
    return 0;
}
