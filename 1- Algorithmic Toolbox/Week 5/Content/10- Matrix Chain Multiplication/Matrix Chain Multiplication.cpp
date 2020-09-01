#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MatrixChain(int Matrices[], int numberOfMatrices)
{
    int multiplicationTable[numberOfMatrices][numberOfMatrices];
    int S[numberOfMatrices][numberOfMatrices];

    // it costs 0 when you multiply one matrix.
    for (int i = 1; i < numberOfMatrices; i++)
        multiplicationTable[i][i] = 0;

    for (int chainLength = 2; chainLength < numberOfMatrices; chainLength++)
    {
        for (int i = 1; i < numberOfMatrices - chainLength + 1; i++)
        {
            int j = i + chainLength - 1;
            multiplicationTable[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int Result = multiplicationTable[i][k] + multiplicationTable[k + 1][j] + Matrices[i - 1] * Matrices[k] * Matrices[j];

                if (Result < multiplicationTable[i][j])
                {
                    multiplicationTable[i][j] = Result;
                    S[i][j] = k;
                }
            }
        }
    }
    cout << "Answer : ";
    return multiplicationTable[1][numberOfMatrices - 1], S[1][numberOfMatrices - 1];
}

int main()
{
    int Matrices[4] = {1, 2, 3, 4};
    cout << MatrixChain(Matrices, 4);
}