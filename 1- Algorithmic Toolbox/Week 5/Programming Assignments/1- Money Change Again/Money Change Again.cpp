//Time complexity of the solution is O(numberOfCoins*Money).
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int moneyChange(int Coins[], int numberOfCoins, int Money)
{
    int Table[Money + 1];

    Table[0] = 0;

    // Initialize all Table values as Infinite
    for (int i = 1; i <= Money; i++)
        Table[i] = INT_MAX;

    for (int i = 1; i <= Money; i++)
    {
        // Go through all coins smaller than i
        for (int j = 0; j < numberOfCoins; j++)
            if (Coins[j] <= i)
            {
                int sub_res = Table[i - Coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < Table[i])
                    Table[i] = sub_res + 1;
            }
    }
    return Table[Money];
}

int main()
{
    int Coins[3] = {1, 3, 4};
    int Money;
    cin >> Money;
    cout << moneyChange(Coins, 3, Money);
    return 0;
}