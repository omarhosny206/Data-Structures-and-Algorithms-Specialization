#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int vertices;
    list<int> *adjacencyList;

public:
    // function to create the graph.
    Graph(int vertices_)
    {
        this->vertices = vertices_;
        this->adjacencyList = new list<int>[vertices_];
    }

    // function to add edge for an directed graph
    void addEdge(int source, int destination)
    {
        this->adjacencyList[source].push_back(destination);
    }

    // DFS_Helper function
    void DFS_Helper(int vertex_, bool visited[])
    {
        visited[vertex_] = true;

        cout << vertex_ << " ";

        list<int>::iterator i;

        for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            if (!visited[*i])
                DFS_Helper(*i, visited);
    }

    // DFSfunction
    void DFS(int vertex_)
    {
        // Mark all the vertices as not visited
        bool *visited = new bool[this->vertices];
        for (int i = 0; i < this->vertices; i++)
            visited[i] = false;

        DFS_Helper(vertex_, visited);
    }

    // BFS funcion
    void BFS(int vertex_)
    {
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
            cout << vertex_ << " ";
            BFS_Queue.pop_front();

            for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    BFS_Queue.push_back(*i);
                }
            }
        }
    }
};

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    cout << "DFS Output : ";
    graph.DFS(2);
    cout << "\nBFS Output : ";
    graph.BFS(2);
}