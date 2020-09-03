#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class Graph
{
private:
    int vertices;
    list<pair<int, int>> *adjacencyList;

public:
    // function to create the graph.
    Graph(int vertices_)
    {
        this->vertices = vertices_;
        this->adjacencyList = new list<pair<int, int>>[vertices_];
    }

    // function to add edge for an directed graph
    void addEdge(int source, int destination, int weight)
    {
        this->adjacencyList[source].push_back(make_pair(destination, weight));
    }

    int Dijkstra(int source, int destination)
    {
        // Create a set to store vertices that are being prerocessed
        set<pair<int, int>> prerocessedVertices;

        vector<int> distance(this->vertices, INF);

        prerocessedVertices.insert(make_pair(0, source));
        distance[source] = 0;

        while (!prerocessedVertices.empty())
        {
            pair<int, int> temporary = *(prerocessedVertices.begin());
            prerocessedVertices.erase(prerocessedVertices.begin());

            int u = temporary.second;

            list<pair<int, int>>::iterator i;

            for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
            {
                int vertex_ = (*i).first;
                int weight_ = (*i).second;

                if (distance[vertex_] > distance[u] + weight_)
                {

                    if (distance[vertex_] != INF)
                        prerocessedVertices.erase(prerocessedVertices.find(make_pair(distance[vertex_], vertex_)));

                    distance[vertex_] = distance[u] + weight_;
                    prerocessedVertices.insert(make_pair(distance[vertex_], vertex_));
                }
            }
        }

        if (distance[destination] == INF)
            return -1;
        return distance[destination];
    }
};

int main()
{
    int vertices, numConnects;
    cin >> vertices >> numConnects;
    Graph graph(vertices+1);
    for (int i = 0; i < numConnects; i++)
    {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }
    int source, destination;
    cin >> source >> destination;
    cout << graph.Dijkstra(source, destination);
}