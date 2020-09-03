#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

class Graph
{
private:
    int vertices;
    list<int> *adjacencyList;

public:
    Graph(int vertices_)
    {
        this->vertices = vertices_;
        adjacencyList = new list<int>[vertices_];
    }

    void addEdge(int source_, int destination_)
    {
        adjacencyList[source_].push_back(destination_);
        adjacencyList[destination_].push_back(source_);
    }

    void DFS_Helper(int vertex_, bool visited[])
    {
        visited[vertex_] = true;

        list<int>::iterator i;
        for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            if (!visited[*i])
                DFS_Helper(*i, visited);
    }

    bool findReachability(int source, int destination)
    {
        int numConnectedComponents = 0;
        bool *visited = new bool[vertices];

        for (int i = 1; i < vertices; i++)
        {
            visited[i] = false;
        }

        DFS_Helper(source, visited);
        numConnectedComponents++;
        return visited[source] == visited[destination];
    }
};

int main()
{
    int numVertices, numConnetcs;
    cin >> numVertices >> numConnetcs;
    Graph graph(numVertices + 1);
    for (int i = 0; i < numConnetcs; i++)
    {
        int source, destination;
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }
    int source, destination;
    cin >> source >> destination;
    cout << graph.findReachability(source, destination);
}