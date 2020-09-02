#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

#define MY_INT64_Minimum (-9223372036854775807 - 1)
#define MY_INT64_Maximum 9223372036854775807

struct Node
{
    int Key;
    int Left;
    int Right;

    Node() : Key(0), Left(-1), Right(-1) {}
    Node(int Key, int Left, int Right) : Key(Key), Left(Left), Right(Right) {}
};

bool isBST_Helper(const vector<Node> &Tree, const int &nodeIndex, long long Minimum, long long Maximum)
{

    if (nodeIndex == -1)
        return true;

    /* false if this node violates the Minimum/Maximum constraint */
    if (Tree[nodeIndex].Key < Minimum || Tree[nodeIndex].Key >= Maximum)
        return false;

    return isBST_Helper(Tree, Tree[nodeIndex].Left, Minimum, (Tree[nodeIndex].Key)) && isBST_Helper(Tree, Tree[nodeIndex].Right, (Tree[nodeIndex].Key), Maximum);
}

bool IsBinarySearchTree(const vector<Node> &Tree)
{
    if (Tree.size() == 0)
        return true;

    return isBST_Helper(Tree, 0, MY_INT64_Minimum, MY_INT64_Maximum);
}

int main()
{
    int Size;
    cin >> Size;
    vector<Node> Tree;
    for (int i = 0; i < Size; ++i)
    {
        int Key, Left, Right;
        cin >> Key >> Left >> Right;
        Tree.push_back(Node(Key, Left, Right));
    }

    if (IsBinarySearchTree(Tree))
    {
        cout << "CORRECT" << endl;
    }
    else
    {
        cout << "INCORRECT" << endl;
    }
    return 0;
}