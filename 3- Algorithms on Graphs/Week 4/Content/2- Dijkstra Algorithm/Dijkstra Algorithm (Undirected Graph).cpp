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
        this->adjacencyList[destination].push_back(make_pair(source, weight));
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

            int source_vertex = temporary.second;

            list<pair<int, int>>::iterator i;

            for (i = adjacencyList[source_vertex].begin(); i != adjacencyList[source_vertex].end(); ++i)
            {
                int destination_vertex = (*i).first;
                int weight_ = (*i).second;

                if (distance[destination_vertex] > distance[source_vertex] + weight_)
                {

                    if (distance[destination_vertex] != INF)
                        prerocessedVertices.erase(prerocessedVertices.find(make_pair(distance[destination_vertex], destination_vertex)));

                    distance[destination_vertex] = distance[source_vertex] + weight_;
                    prerocessedVertices.insert(make_pair(distance[destination_vertex], destination_vertex));
                }
            }
        }
        cout << "(" << source << " --> " << destination << ") = ";
        return distance[destination];
    }
};

int main()
{
    Graph graph(7);
    graph.addEdge(1, 2, 50);
    graph.addEdge(1, 3, 45);
    graph.addEdge(1, 4, 10);
    graph.addEdge(2, 3, 10);
    graph.addEdge(2, 4, 15);
    graph.addEdge(3, 5, 30);
    graph.addEdge(4, 5, 15);
    graph.addEdge(5, 2, 20);
    graph.addEdge(6, 5, 3);
    cout << graph.Dijkstra(1, 4);
}