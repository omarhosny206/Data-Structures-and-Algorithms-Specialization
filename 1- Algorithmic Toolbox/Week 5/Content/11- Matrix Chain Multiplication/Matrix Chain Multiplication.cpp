#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MatrixChain(int Matrices[], int numberOfMatrices)
{
    int multiplicationTable[numberOfMatrices][numberOfMatrices];

    // it costs 0 when you multiply one matrix.
    for (int i = 1; i < numberOfMatrices; i++)
        multiplicationTable[i][i] = 0;

    for (int chainLength = 1; chainLength < numberOfMatrices - 1; chainLength++)
    {
        for (int i = 1; i < numberOfMatrices - chainLength; i++)
        {
            multiplicationTable[i][i + chainLength] = min(multiplicationTable[i][i + chainLength] + Matrices[i - 1] * Matrices[i] * Matrices[i + chainLength],
                                                          multiplicationTable[i][i + chainLength - 1] + Matrices[i - 1] * Matrices[i + chainLength - 1] * Matrices[i + chainLength]);
            cout << multiplicationTable[i][i + chainLength] << "\t\t";
        }
        cout << endl;
    }
    cout << "answer : ";
    return multiplicationTable[1][numberOfMatrices - 1];
}

int main()
{
    int Matrices[5] = {1, 2, 8, 4, 3};
    cout << MatrixChain(Matrices, 5);
}