//Time Complexity is O(mn)

/* 
    LCS[i][j] = 0                                   if i=0, j=0
              = LCS[i-1, j-1] + 1                   if i,j > 0, String1[i] = String2[j]
              = Max(LCS[i, j-1], LCS[i-1, j])       if i,j > 0, String1[i] != String2[j]
*/

// ↖, ⟵, ↑ Bridges

/*
    String1 = "abcbdab", String2 = "bdcaba"    
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int LCS(string String1, string String2, int String1_Length, int String2_Length)
{
    int LCS[String1_Length + 1][String2_Length + 1];

    for (int i = 0; i <= String1_Length; i++)
    {
        for (int j = 0; j <= String2_Length; j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;

            else if (String1[i - 1] == String2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;

            else
                LCS[i][j] = Maximum(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    // LCS[String1_Length][String2_Length] contains length of LCS for X[0..n-1] and Y[0..m-1]
    return LCS[String1_Length][String2_Length];
}

int main()
{
    string String1, String2;
    cin >> String1 >> String2;

    cout << LCS(String1, String2, String1.length(), String2.length());
}
