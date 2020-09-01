//Time Complexity is O(mn)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int LCS(int Numbers1[], int Numbers2[], int Numbers1_Length, int Numbers2_Length)
{
    int LCS[Numbers1_Length + 1][Numbers2_Length + 1];

    for (int i = 0; i <= Numbers1_Length; i++)
    {
        for (int j = 0; j <= Numbers2_Length; j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;

            else if (Numbers1[i - 1] == Numbers2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;

            else
                LCS[i][j] = Maximum(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    // LCS[Numbers1_Length][Numbers2_Length] contains length of LCS for X[0..n-1] and Y[0..m-1]
    return LCS[Numbers1_Length][Numbers2_Length];
}

int main()
{
    int Numbers1_Length;
    cin >> Numbers1_Length;
    int Numbers1[Numbers1_Length + 1];
    for (int i = 0; i < Numbers1_Length; i++)
        cin >> Numbers1[i];

    int Numbers2_Length;
    cin >> Numbers2_Length;
    int Numbers2[Numbers2_Length + 1];
    for (int i = 0; i < Numbers2_Length; i++)
        cin >> Numbers2[i];

    cout << LCS(Numbers1, Numbers2, Numbers1_Length, Numbers2_Length);
}
