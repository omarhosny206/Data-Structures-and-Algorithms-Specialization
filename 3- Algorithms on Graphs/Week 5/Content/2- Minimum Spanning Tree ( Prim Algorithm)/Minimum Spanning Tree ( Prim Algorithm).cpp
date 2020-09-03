#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph
{
private:
    int vertices;
    list<pair<int, int>> *adjacencyList;

public:
    Graph(int vertices_)
    {
        this->vertices = vertices_;
        adjacencyList = new list<iPair>[this->vertices];
    }

    void addEdge(int source_, int destination_, int weight_)
    {
        adjacencyList[source_].push_back(make_pair(destination_, weight_));
        adjacencyList[destination_].push_back(make_pair(source_, weight_));
    }

    void Prim()
    {
        priority_queue<iPair, vector<iPair>, greater<iPair>> vertices_priorityQueue;

        int source = 1;

        vector<int> key(this->vertices, INF);
        vector<int> parent(this->vertices, -1);
        vector<bool> inMST(this->vertices, false);

        vertices_priorityQueue.push(make_pair(1, source));
        key[source] = 0;
        int MST = 0;

        while (!vertices_priorityQueue.empty())
        {
            int source_ = vertices_priorityQueue.top().second;
            vertices_priorityQueue.pop();

            inMST[source_] = true;

            list<pair<int, int>>::iterator i;

            for (i = adjacencyList[source_].begin(); i != adjacencyList[source_].end(); i++)
            {
                int destination_ = (*i).first;
                int weight_ = (*i).second;

                if (inMST[destination_] == false && key[destination_] > weight_)
                {
                    key[destination_] = weight_;
                    vertices_priorityQueue.push(make_pair(key[destination_], destination_));
                    parent[destination_] = source_;
                }
            }
        }
        
        for (int i = 1; i < this->vertices; i++)
        {
            cout << key[i] << endl;
            MST += key[i];
        }
        cout << "MST --> "<< MST << endl;
    }
};
int main()
{
    int numVertices, numConnects;
    cin >> numVertices >> numConnects;
    Graph graph(numVertices + 1);
    for (int i = 1; i < numConnects + 1; i++)
    {
        int source_, destination_, weight_;
        cin >> source_ >> destination_ >> weight_;
        graph.addEdge(source_, destination_, weight_);
    }
    graph.Prim();
}