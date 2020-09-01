#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &Numbers)
{
    int Maximum = *max_element(Numbers.begin(), Numbers.end());
    int Minimum = *min_element(Numbers.begin(), Numbers.end());
    int Range = Maximum - Minimum + 1;

    vector<int> Count(Range), Output(Numbers.size());

    for (int i = 0; i < Numbers.size(); i++)
        Count[Numbers[i] - Minimum]++;

    for (int i = 1; i < Count.size(); i++)
        Count[i] += Count[i - 1];

    for (int i = Numbers.size() - 1; i >= 0; i--)
    {
        Output[Count[Numbers[i] - Minimum] - 1] = Numbers[i];
        Count[Numbers[i] - Minimum]--;
    }

    for (int i = 0; i < Numbers.size(); i++)
        Numbers[i] = Output[i];
}

void printNumbers(vector<int> &Numbers)
{
    cout << "[ ";
    for (int i = 0; i < Numbers.size(); i++)
        cout << Numbers[i] << " ";
    cout << " ]\n";
}

int main()
{
    vector<int> Numbers = {-5, -10, 0, -3, 8, 5, -1, 10};
    countSort(Numbers);
    printNumbers(Numbers);
    return 0;
}