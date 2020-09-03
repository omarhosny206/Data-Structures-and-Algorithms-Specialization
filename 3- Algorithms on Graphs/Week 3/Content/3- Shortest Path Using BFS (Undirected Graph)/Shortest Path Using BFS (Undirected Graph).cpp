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
        for (int i=0; i<this->vertices; i++)
            distance[i] = -1;

        distance[vertex_] = 0;

        bool *visited = new bool[this->vertices];
        for (int i = 0; i < this->vertices; i++)
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

    void print()
    {
        bool *visited = new bool[this->vertices];
        for (int i = 0; i < this->vertices; i++)
            visited[i] = false;



        for (int j = 0; j<this->vertices; j++)
        {
            cout << j << " --> ";
            list<int>::iterator i;
            for (i = adjacencyList[j].begin(); i != adjacencyList[j].end(); ++i)
            {
                if (!visited[*i])
                {
                    cout << *i << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph graph(5);
    graph.addEdge(3, 0);
    graph.addEdge(2, 4);
    graph.addEdge(4, 3);
    graph.addEdge(1, 2);
    graph.addEdge(0, 1);
    graph.addEdge(2, 0);
    int from, to;
    cin >> from >> to;
    cout << "Shortest Path : ";
    cout << graph.shortestPath_BFS(from, to) << endl;

    graph.print();
}