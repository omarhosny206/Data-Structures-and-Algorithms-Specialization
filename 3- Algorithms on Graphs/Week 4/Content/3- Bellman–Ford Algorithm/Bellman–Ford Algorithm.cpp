#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class Graph
{
private:
    struct Edge
    {
        int source, destination, weight;
    };

    int vertices, edges;
    Edge *edge;
    int *distance;

public:
    Graph(int vertices_, int edges_)
    {
        this->vertices = vertices_;
        this->edges = edges_;
        this->edge = new Edge[this->edges];
        this->distance = new int[this->vertices];
    }

    void addEdges(int source_, int destination_, int weight_, int position_)
    {
        this->edge[position_].source = source_;
        this->edge[position_].destination = destination_;
        this->edge[position_].weight = weight_;
    }

    void bellmanFord(int source_)
    {
        for (int i = 1; i < this->vertices; i++)
            distance[i] = INF;
        distance[source_] = 0;

        // Relax all edges (vertices - 1) times.
        for (int i = 0; i < this->vertices - 1; i++)
        {
            for (int j = 1; j < this->edges; j++)
            {
                int source_vertex = this->edge[j].source;
                int destination_vertex = this->edge[j].destination;
                int edge_weight = this->edge[j].weight;
                if (distance[source_vertex] + edge_weight < distance[destination_vertex] && distance[source_vertex] != INF)
                {
                    distance[destination_vertex] = distance[source_vertex] + edge_weight;
                }
            }
        }

        Print();
    }

    void Print()
    {
        for (int i = 1; i < this->vertices; i++)
        {
            if (distance[i] == INF)
                cout << "-\n";
            else 
                cout << distance[i] << endl;
        }
    }
};

int main()
{
    int numVertices, numConnects;
    cin >> numVertices >> numConnects;
    Graph graph(numVertices + 1, numConnects + 1);

    for (int i = 1; i < numConnects + 1; i++)
    {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdges(source, destination, weight, i);
    }
    int source;
    cin >> source;
    graph.bellmanFord(1);
}
/* 
test
7 10
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3
1 2 6
1 3 5
*/
