#include <iostream>
#include <vector>
using namespace std;

int64_t firstMAximumPairwiseProduct(vector<int64_t> &Numbers)
{
    int64_t firstMAx = Numbers[0];
    int64_t secondMax = 0;
    bool isRepeated = false;
    for (int i = 1; i < Numbers.size(); i++)
    {
        if (Numbers[i] > firstMAx)
        {
            firstMAx = Numbers[i];
            isRepeated = false;
        }

        else if (Numbers[i] == firstMAx)
        {
            isRepeated = true;
        }
    }

    if (isRepeated)
    {
        secondMax = firstMAx;
        return firstMAx * secondMax;
    }

    for (int i = 0; i < Numbers.size(); i++)
    {
        if (Numbers[i] != firstMAx && Numbers[i] > secondMax)
        {
            secondMax = Numbers[i];
        }
    }
    return firstMAx * secondMax;
}

int main()
{
    int Size;
    cin >> Size;
    vector<int64_t> Numbers(Size);
    for (int i = 0; i < Numbers.size(); i++)
        cin >> Numbers[i];

    cout << firstMAximumPairwiseProduct(Numbers);
}
