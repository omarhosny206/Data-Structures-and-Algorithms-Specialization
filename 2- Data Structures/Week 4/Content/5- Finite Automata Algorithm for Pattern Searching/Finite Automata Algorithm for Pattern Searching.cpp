#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int numberOfChars = 256;

void computeTrans(char *Pattern, int PatternLength, int TF_Table[][numberOfChars])
{
    int i, longestPrefixSuffix = 0, x;

    // Fill entries in first row
    for (x = 0; x < numberOfChars; x++)
        TF_Table[0][x] = 0;
    TF_Table[0][Pattern[0]] = 1;

    // Fill entries in other rows
    for (i = 1; i <= PatternLength; i++)
    {
        // Copy values from row at index longestPrefixSuffix
        for (x = 0; x < numberOfChars; x++)
            TF_Table[i][x] = TF_Table[longestPrefixSuffix][x];

        // Update the entry corresponding to this character
        TF_Table[i][Pattern[i]] = i + 1;

        // Update longestPrefixSuffix for next row to be filled
        if (i < PatternLength)
            longestPrefixSuffix = TF_Table[longestPrefixSuffix][Pattern[i]];
    }
}

/* Prints all occurrences of Pattern in Text */
void Search(char Pattern[], char Text[])
{
    int PatternLength = strlen(Pattern);
    int textLength = strlen(Text);

    int TF_Table[PatternLength + 1][numberOfChars];

    computeTrans(Pattern, PatternLength, TF_Table);

    // process text over FA.
    int i, j = 0;
    for (i = 0; i < textLength; i++)
    {
        j = TF_Table[j][Text[i]];
        if (j == PatternLength)
            cout << "Pattern found at index " << i - PatternLength + 1 << endl;
    }
}

/* Driver code */
int main()
{
    char Text[] = "GEEKS FOR GEEKS";
    char Pattern[] = "GEEKS";
    Search(Pattern, Text);
    return 0;
}

// This is code is contributed by rathbhupendra
