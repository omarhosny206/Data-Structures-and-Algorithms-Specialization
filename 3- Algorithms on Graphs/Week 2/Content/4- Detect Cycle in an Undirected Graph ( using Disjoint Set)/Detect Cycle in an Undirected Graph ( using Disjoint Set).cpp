#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int vertices, edges;
    struct Edge
    {
        int source, destination;
    };
    Edge *edge;
    int *Parent;

public:
    Graph(int vertices_, int edges_)
    {
        this->vertices = vertices_;
        this->edges = edges_;
        this->edge = new Edge[this->edges * sizeof(Edge)];
    }

    void addEdge(int source_, int destination_, int position_)
    {
        this->edge[position_].source = source_;
        this->edge[position_].destination = destination_;
    }

    int Find(int Item)
    {
        if (Parent[Item] == -1)
            return Item;
        return Find(Parent[Item]);
    }

    void Union(int Item1, int Item2)
    {
        int Item1_Set = Find(Item1);
        int Item2_Set = Find(Item2);

        if (Item1_Set != Item2_Set)
            Parent[Item1_Set] = Item2_Set;
    }

    int isCyclic()
    {
        Parent = new int[this->vertices * sizeof(int)];
        memset(Parent, -1, this->vertices * sizeof(int));

        for (int i = 1; i < this->edges; i++)
        {
            int Item1_Set = Find(this->edge[i].source);
            int Item2_Set = Find(this->edge[i].destination);

            if (Item1_Set == Item2_Set)
                return 1;

            Union(Item1_Set, Item2_Set);
        }

        return 0;
    }
};

int main()
{
    int numVertices, numConnects;
    cin >> numVertices >> numConnects;
    Graph graph(numVertices + 1, numConnects + 1);
    for (int i = 1; i < numConnects + 1; i++)
    {
        int source_, destination_;
        cin >> source_ >> destination_;
        graph.addEdge(source_, destination_, i);
    }
    cout << graph.isCyclic();
}