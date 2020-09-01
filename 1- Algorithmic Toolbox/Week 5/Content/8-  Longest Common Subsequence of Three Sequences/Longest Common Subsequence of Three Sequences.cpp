#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int LCS(string String1, string String2, string String3, int String1_Length, int String2_Length, int String3_Length)
{
    int LCS[String1_Length + 1][String2_Length + 1][String3_Length + 1];

    //	bottom up fashion
    for (int i = 0; i <= String1_Length; i++)
    {
        for (int j = 0; j <= String2_Length; j++)
        {
            for (int k = 0; k <= String3_Length; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    LCS[i][j][k] = 0;

                else if (String1[i - 1] == String2[j - 1] && String1[i - 1] == String3[k - 1])
                    LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;

                else
                    LCS[i][j][k] = max(max(LCS[i - 1][j][k], LCS[i][j - 1][k]), LCS[i][j][k - 1]);
            }
        }
    }

    return LCS[String1_Length][String2_Length][String3_Length];
}

int main()
{
    string String1 = "AGGT12";
    string String2 = "12TXAYB";
    string String3 = "12XBA";

    cout << LCS(String1, String2, String3, String1.length(), String2.length(), String3.length());

    return 0;
}
