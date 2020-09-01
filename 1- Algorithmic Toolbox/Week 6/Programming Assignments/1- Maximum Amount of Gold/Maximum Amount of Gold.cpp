// 0-1 Knapsack problem
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int Knapsack(int knapsackCapacity, vector<int> &Weights)
{

	vector<vector<int>> knapsackTable(knapsackCapacity + 1, vector<int>(Weights.size() + 1));

	for (int i = 0; i < knapsackCapacity + 1; i++)
		knapsackTable[i][0] = 0;

	for (int i = 0; i < Weights.size() + 1; i++)
		knapsackTable[0][i] = 0;

	// Build knapsackTable[][] in bottom up manner
	for (int i = 1; i <= Weights.size(); i++)
	{
		for (int Weight = 1; Weight <= knapsackCapacity; Weight++)
		{

			int valuePosition1 = knapsackTable[Weight][i - 1];
			int valuePosition2 = 0;

			if (Weights[i - 1] <= Weight)
				valuePosition2 = knapsackTable[Weight - Weights[i - 1]][i - 1] + Weights[i - 1];

			if (valuePosition1 > valuePosition2)
				knapsackTable[Weight][i] = valuePosition1;
			else
				knapsackTable[Weight][i] = valuePosition2;
		}
	}

	return knapsackTable[knapsackCapacity][Weights.size()];
}

int main()
{
	int knapsackCapacity, numberOfItems;
	cin >> knapsackCapacity >> numberOfItems;
	vector<int> Weights(numberOfItems);

	for (int i = 0; i < numberOfItems; i++)
		cin >> Weights[i];

	cout << Knapsack(knapsackCapacity, Weights);
}
