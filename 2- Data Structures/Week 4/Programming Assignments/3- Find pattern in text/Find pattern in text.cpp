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

void Search(string Text, string Pattern)
{

    string Concatenation = Pattern + "$" + Text;
    int l = Concatenation.length();

    int Z[l];
    getZ(Concatenation, Z);

    for (int i = 0; i < l; ++i)
    {
        if (Z[i] == Pattern.length())
            cout << i - Pattern.length() - 1 << " ";
    }
}

int main()
{
    string Text, Pattern;
    cin >> Pattern >> Text;
    Search(Text, Pattern);
    return 0;
}
