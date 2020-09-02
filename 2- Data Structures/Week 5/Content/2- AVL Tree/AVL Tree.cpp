#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

template <class Type>

class AVL
{
    // attributes
private:
    struct Node
    {
        Node *Left;
        Node *Right;
        Node *Parent;
        Type item;
        int balanceFactor;
    };

    // Root of AVL
    Node *Root;

    // Private Functions!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // new Node initializer function
    void initializeNode(Node *newNode, Type item)
    {
        newNode->item = item;
        newNode->item = item;
        newNode->Left = newNode->Right = newNode->Parent = NULL;
        newNode->balanceFactor = 0;
    }

    // inOrder Traversal recursively
    void inOrder(Node *temporaryNode)
    {

        if (temporaryNode != NULL)
        {
            inOrder(temporaryNode->Left);
            cout << temporaryNode->item << " ";
            inOrder(temporaryNode->Right);
        }
    }

    // preOrder Traversal recursively
    void preOrder(Node *temporaryNode)
    {

        if (temporaryNode != NULL)
        {
            cout << temporaryNode->item << " ";
            preOrder(temporaryNode->Left);
            preOrder(temporaryNode->Right);
        }
    }

    //postOrder Traversal recursively
    void postOrder(Node *temporaryNode)
    {

        if (temporaryNode != NULL)
        {
            postOrder(temporaryNode->Left);
            postOrder(temporaryNode->Right);
            cout << temporaryNode->item << " ";
        }
    }

    // to search for item (recursively)
    Node *searchRecursively(Node *temporaryNode, Type item)
    {

        if (temporaryNode == NULL || temporaryNode->item == item)
            return temporaryNode;

        if (temporaryNode->item > item)
            return searchRecursively(temporaryNode->Left, item);

        return searchRecursively(temporaryNode->Right, item);
    }

    // to remove item (recursively)
    Node *removeRecursively(Node *currentNode, Type item)
    {

        if (currentNode == NULL)
            return currentNode;

        else if (currentNode->item > item)
            currentNode->Left = removeRecursively(currentNode->Left, item);

        else if (currentNode->item < item)
            currentNode->Right = removeRecursively(currentNode->Right, item);

        // now we got the required node
        else
        {

            // case 1: node is a leaf node
            if (currentNode->Left == NULL && currentNode->Right == NULL)
            {
                delete currentNode;
                currentNode = NULL;
            }

            // case 2: node has only one child
            else if (currentNode->Left == NULL)
            {
                Node *temporaryNode = currentNode;
                currentNode = currentNode->Right;
                delete temporaryNode;
            }

            else if (currentNode->Right == NULL)
            {
                Node *temporaryNode = currentNode;
                currentNode = currentNode->Left;
                delete temporaryNode;
            }

            // case 3: has both children
            else
            {
                Node *temporaryNode = getMinRecursively(currentNode->Right);
                currentNode->item = temporaryNode->item;
                currentNode->Right = removeRecursively(currentNode->Right, currentNode->item);
            }
        }

        return currentNode;
    }

    // Balance Factor function
    void Balance(Node *temporaryNode)
    {

        if (temporaryNode->balanceFactor > 1 || temporaryNode->balanceFactor < -1)
        {
            reBalance(temporaryNode);
            return;
        }

        if (temporaryNode->Parent != NULL)
        {

            if (temporaryNode == temporaryNode->Parent->Left)
            {
                temporaryNode->Parent->balanceFactor -= 1;
            }

            if (temporaryNode == temporaryNode->Parent->Right)
            {
                temporaryNode->Parent->balanceFactor += 1;
            }

            if (temporaryNode->Parent->balanceFactor != 0)
            {
                Balance(temporaryNode->Parent);
            }
        }
    }

    // reBalance the tree.
    void reBalance(Node *temporaryNode)
    {

        if (temporaryNode->balanceFactor > 0)
        {

            if (temporaryNode->Right->balanceFactor < 0)
            {
                rightRotation(temporaryNode->Right);
                leftRotation(temporaryNode);
            }

            else
                leftRotation(temporaryNode);
        }

        else if (temporaryNode->balanceFactor < 0)
        {

            if (temporaryNode->Left->balanceFactor > 0)
            {
                leftRotation(temporaryNode->Left);
                rightRotation(temporaryNode);
            }

            else
                rightRotation(temporaryNode);
        }
    }

    void printHelper(Node *Root, string indent, bool last)
    {
        // print the tree structure on the screen
        if (Root != NULL)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "     ";
            }
            else
            {
                cout << "L----";
                indent += "|    ";
            }

            cout << Root->item << "( BF = " << Root->balanceFactor << ")" << endl;

            printHelper(Root->Left, indent, false);
            printHelper(Root->Right, indent, true);
        }
    }

    // max value function
    int maxValue(Type valueOne, Type valueTwo)
    {
        return ((valueOne > valueTwo) ? valueOne : valueTwo);
    }

    // function to find the height.
    int Height(Node *temporaryNode)
    {
        return ((temporaryNode == NULL) ? -1 : temporaryNode->height);
    }

    // right rotation Case
    void rightRotation(Node *parentNode)
    {
        Node *temporaryNode = parentNode->Left;
        parentNode->Left = temporaryNode->Right;

        if (temporaryNode->Right != NULL)
            temporaryNode->Right->Parent = parentNode;

        temporaryNode->Parent = parentNode->Parent;

        if (parentNode->Parent == NULL)
            Root = temporaryNode;

        else if (parentNode == parentNode->Parent->Right)
            parentNode->Parent->Right = temporaryNode;

        else
            parentNode->Parent->Left = temporaryNode;

        temporaryNode->Right = parentNode;
        parentNode->Parent = temporaryNode;

        // update balance factor
        parentNode->balanceFactor += (1 - min(0, temporaryNode->balanceFactor));
        temporaryNode->balanceFactor += (1 + max(0, parentNode->balanceFactor));
    }

    // left rotation Case
    void leftRotation(Node *parentNode)
    {
        Node *temporaryNode = parentNode->Right;
        parentNode->Right = temporaryNode->Left;

        if (temporaryNode->Left != NULL)
            temporaryNode->Left->Parent = parentNode;

        temporaryNode->Parent = parentNode->Parent;

        if (parentNode->Parent == NULL)
            Root = temporaryNode;

        else if (parentNode == parentNode->Parent->Left)
            parentNode->Parent->Left = temporaryNode;

        else
            parentNode->Parent->Right = temporaryNode;

        temporaryNode->Left = parentNode;
        parentNode->Parent = temporaryNode;

        // update balance factor
        parentNode->balanceFactor += (-1 - max(0, temporaryNode->balanceFactor));
        temporaryNode->balanceFactor += (-1 + min(0, parentNode->balanceFactor));
    }

    // to getMax recursively
    Node *getMaxRecursively(Node *temporaryNode)
    {

        while (temporaryNode->Right != NULL)
        {
            temporaryNode = temporaryNode->Right;
        }
        return temporaryNode;
    }

    // to getMin recursively
    Node *getMinRecursively(Node *temporaryNode)
    {

        while (temporaryNode->Left != NULL)
        {
            temporaryNode = temporaryNode->Left;
        }
        return temporaryNode;
    }

    // methods
public:
    // default constructor
    AVL() : Root(NULL) {}

    // to check if BST is empty or not
    bool isEmpty()
    {
        return Root == NULL;
    }

    // to add items to BST (non recursively)
    void Insert(Type addedItem)
    {

        Node *newNode = new Node;
        newNode->item = addedItem;
        newNode->balanceFactor = 0;
        newNode->Left = newNode->Right = newNode->Parent = NULL;

        Node *parentNode = NULL;
        Node *currentNode = Root;

        while (currentNode != NULL)
        {
            parentNode = currentNode;

            if (newNode->item < currentNode->item)
                currentNode = currentNode->Left;

            else
                currentNode = currentNode->Right;
        }

        newNode->Parent = parentNode;

        if (parentNode == NULL)
            Root = newNode;

        else if (newNode->item < parentNode->item)
            parentNode->Left = newNode;
        else
            parentNode->Right = newNode;

        // balance part
        Balance(newNode);
    }

    // remove function
    void Remove(Type item)
    {
        removeRecursively(Root, item);
    }

    // Depth first

    // inOrder Traversal function
    void inOrderTraversal()
    {
        inOrder(Root);
    }

    // preOrder Traversal function
    void preOrderTraversal()
    {
        preOrder(Root);
    }

    // postOrder Traversal function
    void postOrderTraversal()
    {
        postOrder(Root);
    }

    // search function
    bool Search(Type item)
    {
        return searchRecursively(Root, item);
    }

    // to get max item (recursively)
    int getMaxRec()
    {
        getMaxRecursively(Root);
    }

    // to get max item (recursively)
    int getMinRec()
    {
        getMinRecursively(Root);
    }

    // print function
    void printAVL()
    {
        printHelper(Root, " ", true);
    }
};

int main()
{
    AVL<int> AVLTree;
    AVLTree.Insert(12);
    AVLTree.Insert(13);
    AVLTree.Insert(15);
    AVLTree.Insert(17);
    AVLTree.Insert(11);

    AVLTree.printAVL();
    cout << "\n\n\n";

    //cout<<(AVLTree.Search(110))<<endl;
    AVLTree.Remove(17);
    AVLTree.printAVL();
    cout << "\n\n\n";

    AVLTree.Remove(11);
    AVLTree.printAVL();
    cout << "\n\n\n";

    AVLTree.Insert(14);
    AVLTree.printAVL();
}
