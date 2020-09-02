#include <iostream>
using namespace std;

struct Node
{
    int Key;
    Node *Left, *Right;
};

Node *createNewNode(int Item)
{
    Node *newNode = new Node();
    newNode->Key = Item;
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

Node *Insert(Node *Node, int Key)
{
    // If the tree is empty, return a new Node
    if (Node == NULL)
        return createNewNode(Key);

    // Otherwise, recur down the tree
    if (Key < Node->Key)
        Node->Left = Insert(Node->Left, Key);

    else if (Key > Node->Key)
        Node->Right = Insert(Node->Right, Key);

    // return the (unchanged) Node pointer
    return Node;
}

int sizeOfTree(Node *Root)
{
    if (Root == NULL)
        return 0;

    // Calculate Left size recursively
    int Left = sizeOfTree(Root->Left);

    // Calculate Right size recursively
    int Right = sizeOfTree(Root->Right);

    // Return total size recursively
    return (Left + Right + 1);
}

void storeInorder(Node *Root, int inOrder[], int &Index)
{
    // Base condition
    if (Root == NULL)
    {
        return;
    }

    // Left recursive call
    storeInorder(Root->Left, inOrder, Index);

    // Store elements in inorder array
    inOrder[Index++] = Root->Key;

    // Right recursive call
    storeInorder(Root->Right, inOrder, Index);
}

int getSplittingIndex(int inOrder[], int Index, int Key)
{
    for (int i = 0; i < Index; i++)
    {
        if (inOrder[i] >= Key)
        {
            return i - 1;
        }
    }
    return Index - 1;
}

Node *createBST(int inOrder[], int Start, int End)
{
    // Base Condition
    if (Start > End)
        return NULL;

    // Calculate the Middle of the array
    int Middle = (Start + End) / 2;
    Node *temporaryNode = createNewNode(inOrder[Middle]);

    // Recursive call for Left child
    temporaryNode->Left = createBST(inOrder, Start, Middle - 1);

    // Recursive call for Right child
    temporaryNode->Right = createBST(inOrder, Middle + 1, End);

    // Return newly created Balanced Binary Search Tree
    return temporaryNode;
}

void inorderTraversal(Node *Root)
{
    if (Root == NULL)
        return;
    inorderTraversal(Root->Left);
    cout << Root->Key << " ";
    inorderTraversal(Root->Right);
}

void splitBST(Node *Root, int Key)
{
    // Print the original BST
    cout << "Original BST : ";

    if (Root != NULL)
        inorderTraversal(Root);

    else
        cout << "NULL";

    cout << endl;

    // Store the size of BST1
    int numberOfNodes = sizeOfTree(Root);

    int inOrder[numberOfNodes + 1];
    int Index = 0;

    storeInorder(Root, inOrder, Index);

    int splitIndex = getSplittingIndex(inOrder, Index, Key);

    Node *Root1 = NULL;
    Node *Root2 = NULL;

    if (splitIndex != -1)
        Root1 = createBST(inOrder, 0, splitIndex);

    if (splitIndex != (Index - 1))
        Root2 = createBST(inOrder, splitIndex + 1, Index - 1);

    // Print two Balanced BSTs
    cout << "First BST : ";

    if (Root1 != NULL)
        inorderTraversal(Root1);

    else
        cout << "NULL";

    cout << endl;

    cout << "Second BST : ";
    if (Root2 != NULL)
        inorderTraversal(Root2);

    else
        cout << "NULL";
}

// Driver code
int main()
{

    struct Node *Root = NULL;
    Root = Insert(Root, 5);
    Insert(Root, 3);
    Insert(Root, 2);
    Insert(Root, 4);
    Insert(Root, 7);
    Insert(Root, 6);
    Insert(Root, 8);

    int Key = 5;
    splitBST(Root, Key);

    return 0;
}
