#include <iostream>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int LCS(int Numbers1[], int Numbers2[], int Numbers3[], int Numbers1_Length, int Numbers2_Length, int Numbers3_Length)
{
    int LCS[Numbers1_Length + 1][Numbers2_Length + 1][Numbers3_Length + 1];

    //	bottom up fashion
    for (int i = 0; i <= Numbers1_Length; i++)
    {
        for (int j = 0; j <= Numbers2_Length; j++)
        {
            for (int k = 0; k <= Numbers3_Length; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    LCS[i][j][k] = 0;

                else if (Numbers1[i - 1] == Numbers2[j - 1] && Numbers1[i - 1] == Numbers3[k - 1])
                    LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;

                else
                    LCS[i][j][k] = max(max(LCS[i - 1][j][k], LCS[i][j - 1][k]), LCS[i][j][k - 1]);
            }
        }
    }

    return LCS[Numbers1_Length][Numbers2_Length][Numbers3_Length];
}

int main()
{
    int Numbers1_Length;
    cin >> Numbers1_Length;
    int Numbers1[Numbers1_Length];
    for (int i = 0; i < Numbers1_Length; i++)
        cin >> Numbers1[i];

    int Numbers2_Length;
    cin >> Numbers2_Length;
    int Numbers2[Numbers2_Length];
    for (int i = 0; i < Numbers2_Length; i++)
        cin >> Numbers2[i];

    int Numbers3_Length;
    cin >> Numbers3_Length;
    int Numbers3[Numbers3_Length];
    for (int i = 0; i < Numbers3_Length; i++)
        cin >> Numbers3[i];

    cout << LCS(Numbers1, Numbers2, Numbers3, Numbers1_Length, Numbers2_Length, Numbers3_Length);

    return 0;
}
