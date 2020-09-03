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
    }

    void topologicalSort_Helper(int vertex_, bool visited[], stack<int> &verticesStack)
    {
        visited[vertex_] = true;

        list<int>::iterator i;
        for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            if (!visited[*i])
                topologicalSort_Helper(*i, visited, verticesStack);

        verticesStack.push(vertex_);
    }

    void topologicalSort()
    {
        stack<int> verticesStack;

        bool *visited = new bool[vertices];

        for (int i = 1; i < vertices; i++)
            visited[i] = false;

        for (int i = 1; i < vertices; i++)
        {
            if (visited[i] == false)
                topologicalSort_Helper(i, visited, verticesStack);
        }

        while (verticesStack.empty() == false)
        {
            cout << verticesStack.top() << " ";
            verticesStack.pop();
        }
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

    graph.topologicalSort();
}