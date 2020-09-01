#include <iostream>
#include <cmath>
using namespace std;

int64_t Fibonacci(int64_t Number1, int64_t Number2)
{
    int64_t previousNumber = 0, currentNumber = 1, i;
    if (Number1 <= 1)
        return Number1;

    for (i = 2; i <= Number1; i++)
    {
        int temporaryPreviousNumberry = previousNumber;
        previousNumber = currentNumber;
        currentNumber = (temporaryPreviousNumberry + currentNumber) % Number2;
    }
    return currentNumber;
}

int64_t getPisanoPeriod(int64_t Number2)
{
    int64_t previousNumber = 0, currentNumber = 1, newcurrentNumber = currentNumber + previousNumber;
    for (int64_t i = 0; i < Number2 * Number2; i++)
    {
        newcurrentNumber = (currentNumber + previousNumber) % Number2;
        previousNumber = currentNumber;
        currentNumber = newcurrentNumber;
        if (newcurrentNumber == 1 && previousNumber == 0)
            return i + 1;
    }
}

int64_t getFibonacci(int64_t Number1, int64_t Number2)
{
    int64_t Period = getPisanoPeriod(Number2);
    int64_t Reminder = Number1 % Period;
    return Fibonacci(Reminder, Number2);
}

int main()
{
    int64_t Number1, Number2;
    cin >> Number1 >> Number2;
    cout << getFibonacci(Number1, Number2);
}
