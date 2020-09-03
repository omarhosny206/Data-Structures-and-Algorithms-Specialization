#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjacencyListacencyList[], int edge, int vertex)
{
    adjacencyListacencyList[edge].push_back(vertex);
    adjacencyListacencyList[vertex].push_back(edge);
}

void print(vector<int> adjacencyListacencyList[], int vertex)
{
    for (int i = 0; i < vertex; ++i)
    {
        cout << "\n adjacencyListacency list of vertex " << i << "\n head ";

        for (auto x : adjacencyListacencyList[i])
            cout << "-> " << x;
        cout << "\n";
    }
}

int main()
{
    int vertex = 5;
    vector<int> adjacencyList[vertex];
    addEdge(adjacencyList, 0, 1);
    addEdge(adjacencyList, 0, 4);
    addEdge(adjacencyList, 1, 2);
    addEdge(adjacencyList, 1, 3);
    addEdge(adjacencyList, 1, 4);
    addEdge(adjacencyList, 2, 3);
    addEdge(adjacencyList, 3, 4);
    print(adjacencyList, vertex);
    return 0;
}
