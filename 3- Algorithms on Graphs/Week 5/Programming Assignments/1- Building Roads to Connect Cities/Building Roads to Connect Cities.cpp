#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node
{
    int parent, rank, x, y;
    Node(int x_, int y_, int parent_ = -1, int rank_ = 0)
    {
        x = x_;
        y = y_;
        parent = parent_;
        rank = rank_;
    }
};

struct Edge
{
    int source, destination;
    double weight;
    Edge(int source_, int destination_, double weight_)
    {
        source = source_;
        destination = destination_;
        weight = weight_;
    }
};

bool Compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void makeSet(int i, vector<Node> &nodes, vector<int> &x, vector<int> &y)
{
    nodes.push_back(Node(x[i], y[i], i));
}

double Weight(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int Find(int i, vector<Node> &nodes)
{
    if (i != nodes[i].parent)
        nodes[i].parent = Find(nodes[i].parent, nodes);
    return nodes[i].parent;
}

void Union(int source_, int destination_, vector<Node> &nodes)
{
    int r1 = Find(source_, nodes);
    int r2 = Find(destination_, nodes);
    if (r1 != r2)
    {
        if (nodes[r1].rank > nodes[r2].rank)
        {
            nodes[r2].parent = r1;
        }
        else
        {
            nodes[r1].parent = r2;
            if (nodes[r1].rank == nodes[r2].rank)
            {
                nodes[r2].rank++;
            }
        }
    }
}

double minimum_distance(vector<int> x, vector<int> y)
{
    double result = 0.;
    int n = x.size();
    vector<Node> nodes;

    for (int i = 0; i < n; i++)
        makeSet(i, nodes, x, y);

    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            edges.push_back(Edge(i, j, Weight(x[i], y[i], x[j], y[j])));
    }

    sort(edges.begin(), edges.end(), Compare);

    for (int i = 0; i < edges.size(); i++)
    {
        Edge current_edge = edges[i];
        int source_ = current_edge.source;
        int destination_ = current_edge.destination;
        if (Find(source_, nodes) != Find(destination_, nodes))
        {
            result += current_edge.weight;
            Union(source_, destination_, nodes);
        }
    }
    return result;
}

int main()
{
    int numPoints;
    cin >> numPoints;
    vector<int> x(numPoints), y(numPoints);
    for (int i = 0; i < numPoints; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << setprecision(10) << minimum_distance(x, y) << endl;
}