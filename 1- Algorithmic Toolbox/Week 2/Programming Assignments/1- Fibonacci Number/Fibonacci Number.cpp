#include <iostream>
#include <cstdlib>
using namespace std;

long long Fibonacci(long long Number)
{
    long long previousNumber = 0, currentNumber = 1, newCurrentNumber, i;
    if (Number == 0)
        return previousNumber;
    for (i = 2; i <= Number; i++)
    {
        newCurrentNumber = previousNumber + currentNumber;
        previousNumber = currentNumber;
        currentNumber = newCurrentNumber;
    }
    return currentNumber;
}

int main()
{
    long long Number;
    cin >> Number;
    cout << Fibonacci(Number);
}
