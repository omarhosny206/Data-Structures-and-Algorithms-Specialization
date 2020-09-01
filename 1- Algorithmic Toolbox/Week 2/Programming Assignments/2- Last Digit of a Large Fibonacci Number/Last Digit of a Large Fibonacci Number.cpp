#include <iostream>
using namespace std;

int64_t Fibonacci(int64_t Number)
{
    int64_t previousNumber = 0, currentNumber = 1, i;
    if (Number <= 1)
        return Number;

    for (i = 2; i <= Number; i++)
    {
        int temporaryPreviousNumberry = previousNumber;
        previousNumber = currentNumber;
        currentNumber = (temporaryPreviousNumberry + currentNumber) % 10;
    }
    return currentNumber;
}

int main()
{
    int64_t Number;
    cin >> Number;
    cout << Fibonacci(Number);
}
