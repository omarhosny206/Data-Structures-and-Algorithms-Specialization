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

    void DFS_Helper(int vertex_, bool visited[])
    {
        visited[vertex_] = true;
        list<int>::iterator i;
        for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            if (!visited[*i])
                DFS_Helper(*i, visited);
    }

    Graph getTranspose()
    {
        Graph graph(this->vertices + 1);
        for (int vertex_ = 1; vertex_ < this->vertices; vertex_++)
        {
            list<int>::iterator i;
            for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            {
                graph.adjacencyList[*i].push_back(vertex_);
            }
        }
        return graph;
    }

    void fillOrder(int vertex_, bool visited[], stack<int> &vertexStack)
    {
        visited[vertex_] = true;

        list<int>::iterator i;
        for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            if (!visited[*i])
                fillOrder(*i, visited, vertexStack);

        vertexStack.push(vertex_);
    }

    int stronglyConnectedComponents()
    {
        int numStronglyConnectedComponents = 0;
        stack<int> vertexStack;

        bool *visited = new bool[this->vertices];

        for (int i = 1; i < this->vertices; i++)
            visited[i] = false;

        for (int i = 1; i < this->vertices; i++)
            if (visited[i] == false)
                fillOrder(i, visited, vertexStack);

        Graph reversedGraph = getTranspose();
        for (int i = 1; i < this->vertices; i++)
            visited[i] = false;

        while (vertexStack.empty() == false)
        {
            // Pop a vertex from stack
            int vertex_ = vertexStack.top();
            vertexStack.pop();

            if (visited[vertex_] == false)
            {
                reversedGraph.DFS_Helper(vertex_, visited);
                numStronglyConnectedComponents++;
            }
        }

        return numStronglyConnectedComponents;
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

    cout << graph.stronglyConnectedComponents();
}