#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    //attributes.
    int Value, Weight;
};

// to know the ratio of each item.
bool itemRatio(Item Item1, Item Item2)
{
    double Ratio1 = (double)(Item1.Value / Item1.Weight);
    double Ratio2 = (double)(Item2.Value / Item2.Weight);

    return ((Ratio1 > Ratio2) ? true : false);
}

// using greedy algorithm.
double fractionalKnapsack(int knapsackCapacity, Item itemInformation[], int Size)
{
    // we need to sort the items information.
    sort(itemInformation, itemInformation + Size, itemRatio);

    int currentKnapsackCapacity = 0;
    double knapsackValue = 0;

    for (int i = 0; i < Size; i++)
    {
        // if there is a place to add items.
        if (currentKnapsackCapacity + itemInformation[i].Weight <= knapsackCapacity)
        {
            currentKnapsackCapacity += itemInformation[i].Weight;
            knapsackValue += itemInformation[i].Value;
        }

        // if not.
        else
        {
            int remainingKnapsackCapacity = knapsackCapacity - currentKnapsackCapacity;
            knapsackValue += itemInformation[i].Value * (double)remainingKnapsackCapacity / itemInformation[i].Weight;
            break;
        }
    }

    return knapsackValue;
}

int main()
{
    int knapsackCapacity, Size;
    cin >> Size >> knapsackCapacity;
    Item itemInformation[Size];

    for (int i = 0; i < Size; i++)
        cin >> itemInformation[i].Value >> itemInformation[i].Weight;

    cout << fractionalKnapsack(knapsackCapacity, itemInformation, Size);
}
