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

    int connectedComponents()
    {
        int numConnectedComponents = 0;
        bool *visited = new bool[vertices];

        for (int i = 1; i < vertices; i++)
            visited[i] = false;

        for (int i = 1; i < vertices; i++)
        {
            if (visited[i] == false)
            {
                DFS_Helper(i, visited);
                numConnectedComponents++;
            }
        }
        return numConnectedComponents;
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

    cout << graph.connectedComponents();
}