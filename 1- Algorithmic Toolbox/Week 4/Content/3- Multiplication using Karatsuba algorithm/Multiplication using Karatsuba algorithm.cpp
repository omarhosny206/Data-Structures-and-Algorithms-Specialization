#include <iostream>
#include <stdio.h>
using namespace std;

//Function to make the numbers have the same length.
int makeEqualLength(string &firstNumber, string &secondNumber)
{
    int firstNumberLength = firstNumber.size();
    int secondNumberLength = secondNumber.size();

    if (firstNumberLength < secondNumberLength)
    {
        for (int i = 0; i < secondNumberLength - firstNumberLength; i++)
            firstNumber = '0' + firstNumber;

        return secondNumberLength;
    }

    else if (firstNumberLength > secondNumberLength)
    {
        for (int i = 0; i < firstNumberLength - secondNumberLength; i++)
            secondNumber = '0' + secondNumber;
    }

    // If firstNumberLength >= secondNumberLength.
    return firstNumberLength;
}

// Function to add two bit.
string addTwoBit(string firstNumber, string secondNumber)
{
    // to store the sum.
    string Result;

    int Length = makeEqualLength(firstNumber, secondNumber);
    int Carry = 0;

    // to add all bits one by one.
    for (int i = Length - 1; i >= 0; i--)
    {
        int firstBit = firstNumber.at(i) - '0';
        int secondBit = secondNumber.at(i) - '0';

        // boolean expression for sum of 3 bits.
        int Sum = (firstBit ^ secondBit ^ Carry) + '0';

        Result = (char)Sum + Result;

        // boolean expression for 3-bit addition.
        Carry = (firstBit & secondBit) | (secondBit & Carry) | (firstBit & Carry);
    }

    // if overflow, then add a leading 1
    if (Carry)
        Result = '1' + Result;

    return Result;
}

// A function to multiply single bit.
int multiplyiSingleBit(string firstNumber, string secondNumber)
{
    return (firstNumber[0] - '0') * (secondNumber[0] - '0');
}

//Function to multiply two bit.
long int Multiply(string firstNumber, string secondNumber)
{
    int Length = makeEqualLength(firstNumber, secondNumber);

    if (Length == 0)
        return 0;

    if (Length == 1)
        return multiplyiSingleBit(firstNumber, secondNumber);

    int firstHalf = Length / 2;
    int secondHalf = Length - firstHalf;

    // Find the firstHalf and secondHalf of firstNumber.
    string firstNumber_Left = firstNumber.substr(0, firstHalf);
    string firstNumber_Right = firstNumber.substr(firstHalf, secondHalf);

    // Find the firstHalf and secondHalf of secondNumber.
    string secondNumber_Left = secondNumber.substr(0, firstHalf);
    string secondNumber_Right = secondNumber.substr(firstHalf, secondHalf);

    //Recursively calculate the three products of inputs of size Length/2
    long int Step1 = Multiply(firstNumber_Left, secondNumber_Left);
    long int Step2 = Multiply(firstNumber_Right, secondNumber_Right);
    long int Step3 = Multiply(addTwoBit(firstNumber_Left, firstNumber_Right), addTwoBit(secondNumber_Left, secondNumber_Right));

    // Combine the three products to get the final result.
    return (Step1 * (1 << (2 * secondHalf)) + (Step3 - Step1 - Step2) * (1 << secondHalf) + Step2);
}

int main()
{
    cout << Multiply("1100", "1010");
}
