// 0-1 Knapsack problem
#include <iostream>
#include <string.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int Knapsack(int knapsackCapacity, int Weights[], int Values[], int numberOfItems)
{

    int knapsackTable[numberOfItems + 1][knapsackCapacity + 1];

    // Build knapsackTable[][] in bottom up manner
    for (int i = 0; i <= numberOfItems; i++)
    {
        for (int Weight = 0; Weight <= knapsackCapacity; Weight++)
        {
            if (i == 0 || Weight == 0)
                knapsackTable[i][Weight] = 0;

            else if (Weights[i - 1] <= Weight)
                knapsackTable[i][Weight] = max(Values[i - 1] + knapsackTable[i - 1][Weight - Weights[i - 1]], knapsackTable[i - 1][Weight]);

            else
                knapsackTable[i][Weight] = knapsackTable[i - 1][Weight];
        }
    }

    return knapsackTable[numberOfItems][knapsackCapacity];
}

int main()
{
    int knapsackCapacity, numberOfItems;
    cin >> knapsackCapacity >> numberOfItems;
    int Weights[numberOfItems], Values[numberOfItems];

    for (int i = 0; i < numberOfItems; i++)
    {
        cin >> Weights[i];
        Values[i] = Weights[i];
    }
        

    cout << Knapsack(knapsackCapacity, Weights, Values, numberOfItems);
}
