#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph_Using_AdjacencyList
{
private:
    struct Graph
    {
        int vertices;
        set<int, greater<int>> *adjacencyList;
    };
    Graph *graph;

public:
    // function to create the graph.
    Graph *createGraph(int vertices_)
    {
        graph = new Graph;
        graph->vertices = vertices_;
        graph->adjacencyList = new set<int, greater<int>>[vertices_];
        return graph;
    }

    // function to add edge for undirected graph
    void addEdge(int source, int destination)
    {
        graph->adjacencyList[source].insert(destination);
        graph->adjacencyList[destination].insert(source);
    }

    // function to search for an edge
    void searchEdge(int source, int destination)
    {
        auto iterator = graph->adjacencyList[source].find(destination);

        if (iterator == graph->adjacencyList[source].end())
            cout << "\nEdge from " << source << " to " << destination << " not found." << endl;

        else
            cout << "\nEdge from " << source << " to " << destination << " found." << endl;
    }

    // function to print the graph
    void print()
    {
        for (int i = 0; i < graph->vertices; i++)
        {
            set<int, greater<int>> tempAdjacencyList = graph->adjacencyList[i];
            cout << "\nAdjacency list of vertex : " << i << endl;

            for (auto iterator = tempAdjacencyList.begin(); iterator != tempAdjacencyList.end(); ++iterator)
                cout << *iterator << " ";

            cout << endl;
        }
    }
};
int main()
{
    Graph_Using_AdjacencyList graph;
    graph.createGraph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.print();
    graph.searchEdge(0, 1);
    graph.searchEdge(1, 0);
    graph.searchEdge(0, 3);
    graph.searchEdge(3, 0);
}