#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

// q -> A prime number

void Search(char Pattern[], char Text[], int primeNumber)
{
    int patternLength = strlen(Pattern);
    int textLength = strlen(Text);
    int patternHashValue = 0;
    int textHashValue = 0;
    int h = 1;
    int i, j;

    for (i = 0; i < patternLength - 1; i++)
        h = (h * d) % primeNumber;

    // Calculate the hash value of Pattern and first
    // window of text
    for (i = 0; i < patternLength; i++)
    {
        patternHashValue = (d * patternHashValue + Pattern[i]) % primeNumber;
        textHashValue = (d * textHashValue + Text[i]) % primeNumber;
    }

    // Slide the Pattern over text one by one
    for (i = 0; i <= textLength - patternLength; i++)
    {

        // Check the hash values of current window of text
        // and Pattern. If the hash values match then only
        // check for characters on by one
        if (patternHashValue == textHashValue)
        {
            /* Check for characters one by one */
            for (j = 0; j < patternLength; j++)
            {
                if (Text[i + j] != Pattern[j])
                    break;
            }

            // if p == t and Pattern[0...M-1] = Text[i, i+1, ...i+M-1]
            if (j == patternLength)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < textLength - patternLength)
        {
            textHashValue = (d * (textHashValue - Text[i] * h) + Text[i + patternLength]) % primeNumber;

            // We might get negative value of t, converting it
            // to positive
            if (textHashValue < 0)
                textHashValue = (textHashValue + primeNumber);
        }
    }
}

/* Driver code */
int main()
{
    char Text[] = "abcdhyta";
    char Pattern[] = "abc";
    int primeNumber = 101; // A prime number
    Search(Pattern, Text, primeNumber);
    return 0;
}