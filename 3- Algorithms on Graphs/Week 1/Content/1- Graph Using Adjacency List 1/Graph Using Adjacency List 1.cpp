#include <iostream>
#include <bits/stdc++.h>
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
        this->adjacencyList = new list<int>[this->vertices];
    }

    void addEdge(int source_, int destination_)
    {
        adjacencyList[source_].push_back(destination_);
    }

    bool searchEdge(int source_, int destination_)
    {
        list<int>::iterator i;

        for (i = adjacencyList[source_].begin(); i != adjacencyList[source_].end(); i++)
            if (*i == destination_)
                return true;
        return false;
    }

    void printGraph()
    {
        for (int i = 1; i < this->vertices; i++)
        {
            cout << i << " --> ";
            list<int>::iterator j;
            for (j = adjacencyList[i].begin(); j != adjacencyList[i].end(); j++)
                cout << *j << " ";
            cout << endl;
        }
    }
};

int main()
{
    Graph graph(6);
    graph.addEdge(1, 2);
    graph.addEdge(1, 5);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.printGraph();
    cout << graph.searchEdge(1, 2) << endl;
    cout << graph.searchEdge(2, 1) << endl;
    cout << graph.searchEdge(1, 4) << endl;
    cout << graph.searchEdge(4, 1) << endl;
}