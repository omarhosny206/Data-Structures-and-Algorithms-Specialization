#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int vertices;
    list<int> *adjacencyList;
    int *color;

public:
    // function to create the graph.
    Graph(int vertices_)
    {
        this->vertices = vertices_;
        this->adjacencyList = new list<int>[vertices_];
        this->color =new int[vertices_];
    }

    // function to add edge for an directed graph
    void addEdge(int source, int destination)
    {
        this->adjacencyList[source].push_back(destination);
        this->adjacencyList[destination].push_back(source);
    }


    int isBipartite(int vertex_)
    {
        for (int i=1; i<this->vertices; i++)
            color[i] = 0;

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
                    color[*i] = color[vertex_] + 1;
                    BFS_Queue.push_back(*i);
                }

                else
                    if(color[*i] == color[vertex_])
                        return 0;
            }
        }
        return 1;
    }

    void print()
    {
        cout << "Answer : ";
        cout << isBipartite(1);
        cout << endl;
        for (int i=1; i<this->vertices; i++)
        {
            cout << "color of "<< i << " --> ";
            cout << color[i] <<endl;
        }
    }
};

int main()
{
    Graph graph(6);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(4, 3);
    graph.addEdge(5, 2);
    graph.print();
}