#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
private:
    int vertices, edges;
    vector<pair<int, iPair>> edge;
    struct DisjointSets
    {
        int *parent, *rank;
        int disjointSets_size;

        DisjointSets(int size_)
        {
            this->disjointSets_size = size_;
            this->parent = new int[this->disjointSets_size];
            this->rank = new int[this->disjointSets_size];

            for (int i = 1; i < this->disjointSets_size; i++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int Find(int vertex_)
        {
            if (vertex_ != parent[vertex_])
                parent[vertex_] = Find(parent[vertex_]);
            return parent[vertex_];
        }

        void Union(int vertex_1, int vertex_2)
        {
            int item1_set = Find(vertex_1);
            int item2_set = Find(vertex_2);

            if (rank[item1_set] > rank[item2_set])
                parent[item2_set] = item1_set;

            else
                parent[item1_set] = item2_set;

            if (rank[item1_set] == rank[item2_set])
                rank[item2_set]++;
        }
    };

public:
    Graph(int vertices_, int edges_)
    {
        this->vertices = vertices_;
        this->edges = edges_;
    }

    void addEdge(int source_, int destination_, int weight_)
    {
        edge.push_back({weight_, {source_, destination_}});
    }

    int Kruskal()
    {
        int MST = 0;
        sort(this->edge.begin(), this->edge.end());

        DisjointSets disjoint_Set(this->vertices);

        vector<pair<int, iPair>>::iterator i;

        for (i = this->edge.begin(); i != this->edge.end(); i++)
        {
            int source = i->second.first;
            int destination = i->second.second;

            int source_set = disjoint_Set.Find(source);
            int destination_set = disjoint_Set.Find(destination);

            if (source_set != destination_set)
            {
                // Current edge will be in the MST so print it
                cout << source << " --> " << destination << " = " << i->first << endl;

                // Update MST weight
                MST += i->first;

                // Union two sets
                disjoint_Set.Union(source_set, destination_set);
            }
        }

        return MST;
    }
};

int main()
{
    int numVertices, numConnects;
    cin >> numVertices >> numConnects;
    Graph graph(numVertices + 1, numConnects + 1);
    for (int i = 1; i < numConnects + 1; i++)
    {
        int source_, destination_, weight_;
        cin >> source_ >> destination_ >> weight_;
        graph.addEdge(source_, destination_, weight_);
    }
    cout << graph.Kruskal();
}