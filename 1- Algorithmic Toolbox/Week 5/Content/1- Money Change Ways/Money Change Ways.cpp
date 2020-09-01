#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int changeWays(int Coins[], int numberOfCoins, int Money)
{
    int Count1, Count2;
    int Ways[Money + 1][numberOfCoins];

    for (int i = 0; i < numberOfCoins; i++)
        Ways[0][i] = 1;

    for (int i = 1; i <= Money; i++)
    {
        for (int j = 0; j < numberOfCoins; j++)
        {
            
            Count1 = (i - Coins[j] >= 0) ? Ways[i - Coins[j]][j] : 0;

            
            Count2 = (j >= 1) ? Ways[i][j - 1] : 0;

            // total Count
            Ways[i][j] = Count1 + Count2;
        }
    }

    return Ways[Money][numberOfCoins - 1];
}

int main()
{
    int Coins[3] = {1, 2, 3};
    int Money = 4;
    cout << changeWays(Coins, 3, Money);
    return 0;
}
