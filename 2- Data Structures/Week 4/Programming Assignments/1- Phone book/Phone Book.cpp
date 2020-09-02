#include <iostream>
#include <vector>
#include <string.h>
#include <array>
using namespace std;

struct Query
{
    string Operation;
    string Name;
    int Number;
};

vector<Query> readInput()
{
    int Size;
    cin >> Size;
    vector<Query> Queries(Size);
    for (int i = 0; i < Size; ++i)
    {
        cin >> Queries[i].Operation;
        if (Queries[i].Operation == "add")
            cin >> Queries[i].Number >> Queries[i].Name;
        else
            cin >> Queries[i].Number;
    }
    return Queries;
}

void writeOutput(const vector<string> &Result)
{
    for (int i = 0; i < Result.size(); ++i)
        cout << Result[i] << "\n";
}

vector<string> processQueries(const vector<Query> &Queries)
{
    vector<string> Result;
    const int ContactsSize = 10000000;
    vector<string> Contacts(ContactsSize);

    for (int i = 0; i < Queries.size(); ++i)
        if (Queries[i].Operation == "add")
        {
            Contacts[Queries[i].Number] = Queries[i].Name;
        }
        else if (Queries[i].Operation == "del")
        {
            Contacts[Queries[i].Number] = "";
        }
        else
        {
            if (Contacts[Queries[i].Number] == "")
                Result.push_back("not found");
            else
                Result.push_back(Contacts[Queries[i].Number]);
        }
    return Result;
}

int main()
{
    writeOutput(processQueries(readInput()));
    return 0;
}