#include <iostream>
#include <cassert>
#include <string.h>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

long long Evaluation(long long Number1, long long Number2, char Operation)
{
    if (Operation == '*')
    {
        return Number1 * Number2;
    }
    else if (Operation == '+')
    {
        return Number1 + Number2;
    }
    else if (Operation == '-')
    {
        return Number1 - Number2;
    }
    else
    {
        assert(0);
    }
}

long long getMaximumValue(string &Expression)
{

    int Length = Expression.size();
    int numberOfOperands = (Length + 1) / 2;

    long long minimumTable[numberOfOperands][numberOfOperands];
    long long maximumTable[numberOfOperands][numberOfOperands];

    // initialize to 0
    memset(minimumTable, 0, sizeof(minimumTable));
    memset(maximumTable, 0, sizeof(maximumTable));

    for (int i = 0; i < numberOfOperands; i++)
    {
        //The values on the main diagonal is just the number themselves
        minimumTable[i][i] = stoll(Expression.substr(2 * i, 1));
        maximumTable[i][i] = stoll(Expression.substr(2 * i, 1));
    }

    for (int s = 0; s < numberOfOperands - 1; s++)
    {
        for (int i = 0; i < numberOfOperands - s - 1; i++)
        {
            int j = i + s + 1;
            long long minimumValue = LLONG_MAX;
            long long maximumValue = LLONG_MIN;

            for (int k = i; k < j; k++)
            {
                long long firstMinimum = Evaluation(minimumTable[i][k], minimumTable[k + 1][j], Expression[2 * k + 1]);
                long long secondMinimum = Evaluation(minimumTable[i][k], maximumTable[k + 1][j], Expression[2 * k + 1]);
                long long firstMaximum = Evaluation(maximumTable[i][k], minimumTable[k + 1][j], Expression[2 * k + 1]);
                long long secondMaximum = Evaluation(maximumTable[i][k], maximumTable[k + 1][j], Expression[2 * k + 1]);

                minimumValue = min(minimumValue, min(firstMinimum, min(secondMinimum, min(firstMaximum, secondMaximum))));
                maximumValue = max(maximumValue, max(firstMinimum, max(secondMinimum, max(firstMaximum, secondMaximum))));
            }
            minimumTable[i][j] = minimumValue;
            maximumTable[i][j] = maximumValue;
        }
    }

    return maximumTable[0][numberOfOperands - 1];
}

int main()
{
    string Expression;
    cin >> Expression;
    cout << getMaximumValue(Expression);
}