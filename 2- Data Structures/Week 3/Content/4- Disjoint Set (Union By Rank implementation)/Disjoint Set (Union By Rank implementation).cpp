// O (Log N)
#include <iostream>
using namespace std;

class disjointSet
{
private:
    int *Rank, *Parent, disjointSetSize;

public:
    disjointSet(int Size)
    {
        disjointSetSize = Size;
        Rank = new int[disjointSetSize];
        Parent = new int[disjointSetSize];
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < disjointSetSize; i++)
        {
            Parent[i] = i;
            Rank[i] = 0;
        }
    }

    int Find(int Item)
    {
        while (Parent[Item] != Item)
            Item = Parent[Item];
        return Item;
    }

    void Union(int Item1, int Item2)
    {
        int Item1_Set = Find(Item1);
        int Item2_Set = Find(Item2);

        if (Item1_Set == Item2_Set)
            return;

        if (Rank[Item1_Set] < Rank[Item2_Set])
        {
            Parent[Item1_Set] = Item2_Set;
        }
        else if (Rank[Item1_Set] > Rank[Item2_Set])
        {
            Parent[Item2_Set] = Item1_Set;
        }

        // If Ranks are the same, then increment the Rank.
        else
        {
            Parent[Item2_Set] = Item1_Set;
            Rank[Item1_Set] = Rank[Item1_Set] + 1;
        }
    }
};

int main()
{
    disjointSet DisjointSet(5);
    DisjointSet.Union(0, 2);
    DisjointSet.Union(4, 2);
    DisjointSet.Union(3, 1);

    if (DisjointSet.Find(4) == DisjointSet.Find(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    if (DisjointSet.Find(1) == DisjointSet.Find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
}