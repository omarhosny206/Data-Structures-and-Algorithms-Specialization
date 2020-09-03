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
        cout << vertex_ << " ";
        list<int>::iterator i;
        for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            if (!visited[*i])
                DFS_Helper(*i, visited);
    }
    
    // looks like DFS. 
    bool isCyclic_Helper(int vertex_, bool visited[], bool *recStack)
    {
        if (visited[vertex_] == false)
        {
            visited[vertex_] = true;
            recStack[vertex_] = true;

            list<int>::iterator i;
            for (i = adjacencyList[vertex_].begin(); i != adjacencyList[vertex_].end(); ++i)
            {
                if (!visited[*i] && isCyclic_Helper(*i, visited, recStack))
                    return true;

                else if (recStack[*i])
                    return true;
            }
        }

        recStack[vertex_] = false;
        return false;
    }

    int isCyclic()
    {
        bool *visited = new bool[this->vertices];
        bool *recStack = new bool[this->vertices];

        for (int i = 1; i < this->vertices; i++)
            visited[i] = recStack[i] = false;

        for (int i = 1; i < this->vertices; i++)
            if (isCyclic_Helper(i, visited, recStack))
                return 1;
        return 0;
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

    cout << graph.isCyclic();
}