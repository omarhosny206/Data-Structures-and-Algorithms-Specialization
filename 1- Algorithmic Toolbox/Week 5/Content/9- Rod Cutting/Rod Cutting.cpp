// Time Comlexcity is O(n^2)
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <limits.h>
using namespace std;

int valuesTable_topDown[10];

// buttom - up DP

int rodCutting(int Prices[], int requiredRodLength)
{
    int valuesTable[requiredRodLength + 1];
    valuesTable[0] = 0;

    for (int i = 1; i <= requiredRodLength; i++)
    {

        int maxValue = INT_MIN;
        for (int j = 1; j <= i; j++)
            maxValue = max(maxValue, Prices[j - 1] + valuesTable[i - j]);

        valuesTable[i] = maxValue;
    }
    return valuesTable[requiredRodLength];
}

// buttom - up DP
int rodCutting2(int Prices[], int requiredRodLength)
{
    int valuesTable[requiredRodLength + 1][requiredRodLength + 1];
    for (int i = 0; i <= requiredRodLength; i++)
        valuesTable[0][i] = 0;

    for (int i = 0; i <= requiredRodLength; i++)
        valuesTable[i][0] = 0;

    for (int i = 1; i <= requiredRodLength; i++)
    {

        for (int j = 1; j <= requiredRodLength; j++)
        {
            if (i > j)
            {
                int maxValue = max(valuesTable[i - 1][j], Prices[j - 1]);
                valuesTable[i][j] = maxValue;
            }
            else
            {
                int maxValue = max(valuesTable[i - 1][j], Prices[i - 1] + valuesTable[i][j - i]);
                valuesTable[i][j] = maxValue;
            }
        }
    }
    return valuesTable[requiredRodLength][requiredRodLength];
}

int main()
{

    int requiredRodLength;
    cin >> requiredRodLength;
    int Prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << rodCutting(Prices, requiredRodLength) << endl;
}