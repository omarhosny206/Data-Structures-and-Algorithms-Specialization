#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int vertices;
    list<int> *adjacencyList;
    int *distance;

public:
    // function to create the graph.
    Graph(int vertices_)
    {
        this->vertices = vertices_;
        this->adjacencyList = new list<int>[vertices_];
    }

    void addEdge(int source, int destination)
    {
        this->adjacencyList[source].push_back(destination);
        this->adjacencyList[destination].push_back(source);
    }


    int shortestPath_BFS(int vertex_, int requiredVertex_)
    {
        if (vertex_ == requiredVertex_)
            return 0;

        distance = new int[this->vertices];
        for (int i=1; i<this->vertices; i++)
            distance[i] = -1;

        distance[vertex_] = 0;

        bool *visited = new bool[this->vertices];
        for (int i = 1; i < this->vertices; i++)
            visited[i] = false;

        list<int> BFS_Queue;

        visited[vertex_] = true;
        BFS_Queue.push_back(vertex_);

        list<int>::iterator i;

        while (!BFS_Queue.empty())
        {

            vertex_ = BFS_Queue.front();
            BFS_Queue.pop_front();

            for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    distance[*i] = distance[vertex_] + 1;
                    BFS_Queue.push_back(*i);

                    if (*i == requiredVertex_)
                        return distance[*i];
                }
            }
        }

        return -1;
    }
};

int main()
{
    int vertices, numConnects;
    cin >> vertices >> numConnects;
    Graph graph(vertices+1);
    for (int i = 0; i < numConnects; i++)
    {
        int source, destination;
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }
    int from, to;
    cin >> from >> to;

    cout << graph.shortestPath_BFS(from, to);
}