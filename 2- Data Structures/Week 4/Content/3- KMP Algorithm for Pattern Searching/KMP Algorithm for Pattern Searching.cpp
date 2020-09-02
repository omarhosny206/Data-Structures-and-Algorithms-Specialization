#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Fills longestPrefixSuffix[] for given Patternt Pattern[0..patternLength-1]
void computelongestPrefixSuffix(char *Pattern, int patternLength, int *longestPrefixSuffix)
{
    // length of the previous longest prefix suffix
    int Length = 0;

    longestPrefixSuffix[0] = 0; // longestPrefixSuffix[0] is always 0

    // the loop calculates longestPrefixSuffix[i] for i = 1 to M-1
    int i = 1;
    while (i < patternLength)
    {
        if (Pattern[i] == Pattern[Length])
        {
            Length++;
            longestPrefixSuffix[i] = Length;
            i++;
        }
        else // (Pattern[i] != Pattern[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (Length != 0)
            {
                Length = longestPrefixSuffix[Length - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                longestPrefixSuffix[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of Text[] in Pattern[]
void KMPSearch(char *Pattern, char *Text)
{
    int patternLength = strlen(Pattern);
    int textLength = strlen(Text);

    // create longestPrefixSuffix[] that will hold the longest prefix suffix values for Pattern.
    int longestPrefixSuffix[patternLength];

    // Preprocess the Pattern(calculate longestPrefixSuffix[] )
    computelongestPrefixSuffix(Pattern, patternLength, longestPrefixSuffix);

    int i = 0; // index for Text[]
    int j = 0; // index for Pattern[]
    while (i < textLength)
    {
        if (Pattern[j] == Text[i])
        {
            j++;
            i++;
        }

        if (j == patternLength)
        {
            printf("Found Pattern at index %d ", i - j);
            j = longestPrefixSuffix[j - 1];
        }

        // mismatch after j matches
        else if (i < textLength && Pattern[j] != Text[i])
        {
            // Do not match longestPrefixSuffix[0..longestPrefixSuffix[j-1]] characters,they will match anyway
            if (j != 0)
                j = longestPrefixSuffix[j - 1];
            else
                i = i + 1;
        }
    }
}

// Driver program to test above function
int main()
{
    char Text[] = "ABABDABACDABABCABAB";
    char Pattern[] = "ABABCABAB";
    KMPSearch(Pattern, Text);
    return 0;
}
