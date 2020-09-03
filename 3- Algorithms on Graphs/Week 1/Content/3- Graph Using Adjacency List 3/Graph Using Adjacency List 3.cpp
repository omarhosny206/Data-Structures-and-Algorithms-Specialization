#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string number;
    cin >> number;
    int luckyNumbers = 0;
    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] == '4' || number[i] == '7')
            luckyNumbers = luckyNumbers + 1;
    }
    cout << luckyNumbers;
}