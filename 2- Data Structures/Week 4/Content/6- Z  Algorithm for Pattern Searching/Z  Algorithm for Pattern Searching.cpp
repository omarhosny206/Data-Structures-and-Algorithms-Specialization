#include <iostream>
using namespace std;

void getZ(string String, int Z[])
{
    int stringLength = String.length();
    int L, R, k;

    L = R = 0;
    for (int i = 1; i < stringLength; ++i)
    {
        if (i > R)
        {
            L = R = i;

            while (R < stringLength && String[R - L] == String[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            k = i - L;

            if (Z[k] < R - i + 1)
                Z[i] = Z[k];

            else
            {
                L = i;
                while (R < stringLength && String[R - L] == String[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

void search(string text, string pattern)
{
    string concat = pattern + "$" + text;
    int l = concat.length();

    int Z[l];
    getZ(concat, Z);

    for (int i = 0; i < l; ++i)
    {
        if (Z[i] == pattern.length())
        {
            cout << "Pattern found at index " << i - pattern.length() - 1 << endl;
        }
    }
}

int main()
{
    string text = "ABAXXXAB";
    string pattern = "AB";
    search(text, pattern);
    return 0;
}
