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
    bool *visited;

public:
    Graph(int vertices_, int edges_)
    {
        this->vertices = vertices_;
        this->edges = edges_;
        this->edge = new Edge[this->edges];
        this->distance = new int[this->vertices];
        this->visited = new bool[this->vertices];
    }

    void addEdges(int source_, int destination_, int weight_, int position_)
    {
        this->edge[position_].source = source_;
        this->edge[position_].destination = destination_;
        this->edge[position_].weight = weight_;
    }

    int bellmanFord(int source_)
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

        // check for negative-weight cycle --> If we get a shorter path again --> then there is a cycle.
        for (int i = 1; i < this->edges; i++)
        {
            int source_vertex = this->edge[i].source;
            int destination_vertex = this->edge[i].destination;
            int edge_weight = this->edge[i].weight;
            if (distance[source_vertex] + edge_weight < distance[destination_vertex] && distance[source_vertex] != INF)
            {
                return 1;
            }
        }

        return 0;
    }

    int hasNegativeCycle_Disconnected()
    {
        memset(visited, 0, sizeof(visited));

        for (int i = 1; i < this->vertices; i++)
        {
            if (visited[i] == false)
            {
                if (this->bellmanFord(i))
                    return 1;
            }

            for (int j = 1; j < this->vertices; j++)
            {
                if (this->distance[j] != INF)
                    this->visited[j] = true;
            }
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
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdges(source, destination, weight, i);
    }

    cout << graph.hasNegativeCycle_Disconnected();
}
