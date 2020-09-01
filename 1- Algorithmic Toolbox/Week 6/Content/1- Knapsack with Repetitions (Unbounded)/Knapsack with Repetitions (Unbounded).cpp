#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int knapsackCapacity, int Values[], int Weights[], int itemsSize)
{
    //To store maximum Value
    int DP[knapsackCapacity + 1];
    memset(DP, 0, sizeof DP);

    for (int i = 0; i <= knapsackCapacity; i++)
        for (int j = 0; j < itemsSize; j++)
            if (Weights[j] <= i)
                DP[i] = max(DP[i], DP[i - Weights[j]] + Values[j]);

    return DP[knapsackCapacity];
}

int main()
{
    int knapsackCapacity;
    cin >> knapsackCapacity;
    int itemsSize;
    cin >> itemsSize;

    int Values[itemsSize], Weights[itemsSize];

    for (int i = 0; i < itemsSize; i++)
        cin >> Values[i];

    for (int i = 0; i < itemsSize; i++)
        cin >> Weights[i];

    cout << unboundedKnapsack(knapsackCapacity, Values, Weights, itemsSize);
}