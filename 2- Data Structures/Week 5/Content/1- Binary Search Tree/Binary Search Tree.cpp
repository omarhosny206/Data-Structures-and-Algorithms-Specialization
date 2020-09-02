#include <iostream>
#include <queue>
using namespace std;

template <class Type>

class BST
{
    // attributes
private:
    struct Node
    {
        Node *Left;
        Node *headcacs;
        Node *Right;
        Type item;
    };

    // Root of BST
    Node *Root;

    // Private Functions!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // to add recursively
    void addRecursively(Node *temporaryNode, Type addedItem)
    {

        if (temporaryNode->item < addedItem)
        {

            if (temporaryNode->Right == NULL)
            {
                Node *newNode = new Node;
                newNode->item = addedItem;
                newNode->Left = newNode->Right = NULL;
                temporaryNode->Right = newNode;
            }

            else
            {
                addRecursively(temporaryNode->Right, addedItem);
            }
        }

        else
        {
            if (temporaryNode->Left == NULL)
            {
                Node *newNode = new Node;
                newNode->item = addedItem;
                newNode->Left = newNode->Right = NULL;
                temporaryNode->Left = newNode;
            }

            else
            {
                addRecursively(temporaryNode->Left, addedItem);
            }
        }
    }

    // to getMax recursively
    int getMaxRecursively(Node *temporaryNode)
    {

        if (temporaryNode->Right == NULL)
            return temporaryNode->item;

        else
            return getMaxRecursively(temporaryNode->Right);
    }

    // to getMin recursively
    int getMinRecursively(Node *temporaryNode)
    {

        if (temporaryNode->Left == NULL)
            return temporaryNode->item;

        else
            return getMaxRecursively(temporaryNode->Left);
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

    // to get the height (recursively)
    int heightRecursively(Node *temporaryNode)
    {

        if (temporaryNode == NULL)
            return -1;

        else
        {
            int leftSubTree = heightRecursively(temporaryNode->Left);
            int rightSubTree = heightRecursively(temporaryNode->Right);
            return (1 + max(leftSubTree, rightSubTree));
        }
    }

    // to remove item (recursively)
    Node *removeRecursively(Node *Root, Type item)
    {

        if (!isEmpty())
        {

            if (Root->item < item)
                Root->Right = removeRecursively(Root->Right, item);

            else if (Root->item > item)
                Root->Left = removeRecursively(Root->Left, item);

            // now we reached the required Node
            else if (Root->item == item)
            {

                if (Root->Left == NULL)
                {
                    Node *temporaryNode = Root->Right;
                    delete Root;
                    return temporaryNode;
                }

                else if (Root->Right == NULL)
                {
                    Node *temporaryNode = Root->Left;
                    delete Root;
                    return temporaryNode;
                }

                else
                {
                    Type maxValue = this->getMaxRecursively(Root->Left);
                    Root->item = maxValue;
                    Root->Left = removeRecursively(Root->Left, Root->item);
                }
            }
        }

        else
            return Root;

        return Root;
    }

    // to search for item (recursively)
    bool searchRecursively(Node *temporaryNode, Type item)
    {

        if (temporaryNode == NULL)
            return false;

        else if (temporaryNode->item == item)
            return true;

        else if (temporaryNode->item > item)
            return searchRecursively(temporaryNode->Left, item);

        else
            return searchRecursively(temporaryNode->Right, item);
    }

    // to count the leaves of the tree (recursively)
    int countLeavesRecursively(Node *temporaryNode)
    {

        if (temporaryNode == NULL)
            return 0;

        else if ((temporaryNode->Left == NULL) && (temporaryNode->Right == NULL))
            return 1;

        else
            return countLeavesRecursively(temporaryNode->Left) + countLeavesRecursively(temporaryNode->Right);
    }

    int countNodesRecursively(Node *temporaryNode)
    {

        if (temporaryNode == NULL)
            return 0;

        else
            return (1 + countNodesRecursively(temporaryNode->Left) + countNodesRecursively(temporaryNode->Right));
    }

    // clear the tree (recursively)
    void clearRecursively(Node *temporaryNode)
    {

        if (temporaryNode != NULL)
        {
            clearRecursively(temporaryNode->Left);
            clearRecursively(temporaryNode->Right);
            delete temporaryNode;
            temporaryNode = NULL;
        }
    }

    //methods
public:
    // default constructor
    BST() : Root(NULL) {}

    // to check if BST is empty or not
    bool isEmpty()
    {
        return Root == NULL;
    };

    // to add items to BST (non recursively)
    void Insert(Type addedItem)
    {

        Node *newNode = new Node;
        newNode->item = addedItem;
        newNode->Left = newNode->Right = NULL;

        // if BST is empty
        if (isEmpty())
            Root = newNode;

        else
        {
            // create temporaryNode
            Node *temporaryNode = Root;
            // create currentNode to move between nodes
            Node *currentNode;

            while (temporaryNode != NULL)
            {
                currentNode = temporaryNode; // to have currentNode

                if (temporaryNode->item < addedItem)
                    temporaryNode = temporaryNode->Right;

                else
                    temporaryNode = temporaryNode->Left;
            }

            // now we reached to the required node

            if (currentNode->item < addedItem)
                currentNode->Right = newNode;

            else
                currentNode->Left = newNode;
        }
    }

    // to add items to BST (recursively)
    void insertRec(Type addedItem)
    {

        // if BST is empty
        if (isEmpty())
        {
            Node *newNode = new Node;
            newNode->item = addedItem;
            newNode->Left = newNode->Right = NULL;
            Root = newNode;
        }

        else
        {
            addRecursively(Root, addedItem);
        }
    }

    // to get max item (non recursively)
    int getMax()
    {

        if (isEmpty())
            return 0;

        else
        {
            // create temporaryNode
            Node *temporaryNode = Root;

            while (temporaryNode->Right != NULL)
            {
                temporaryNode = temporaryNode->Right;
            }
            return temporaryNode->item;
        }
    }

    // to get max item (recursively)
    int getMaxRec()
    {
        getMaxRecursively(Root);
    }

    // to get min item (non recursively)
    int getMin()
    {

        if (isEmpty())
            return 0;

        else
        {
            // create temporaryNode
            Node *temporaryNode = Root;

            while (temporaryNode->Left != NULL)
            {
                temporaryNode = temporaryNode->Left;
            }
            return temporaryNode->item;
        }
    }

    // to get max item (recursively)
    int getMinRec()
    {
        getMinRecursively(Root);
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

    // Breadth first (level order)
    void levelOrder()
    {

        if (isEmpty())
            return;

        else
        {
            queue<Node *> queueNode;
            queueNode.push(Root);

            while (!queueNode.empty())
            {
                Node *currentNode = queueNode.front();
                queueNode.pop();

                cout << currentNode->item << ", ";

                if (currentNode->Left != NULL)
                    queueNode.push(currentNode->Left);

                if (currentNode->Right != NULL)
                    queueNode.push(currentNode->Right);
            }
        }
        cout << "\n";
    }

    // to get the height.
    int Height()
    {

        if (isEmpty())
            return -1;

        else
            return (heightRecursively(Root));
    }

    // function to remove item.
    void Remove(Type removedItem)
    {

        if (isEmpty())
            cout << "wrong!\n";

        else
            Root = removeRecursively(Root, removedItem);
    }

    // search function
    bool Search(Type item)
    {
        return searchRecursively(Root, item);
    }

    // function to count Nodes
    int countNodes()
    {
        return countNodesRecursively(Root);
    }

    // to count leaves
    int countLeaves()
    {
        return countLeavesRecursively(Root);
    }

    // function to clear the tree
    void Clear()
    {
        clearRecursively(Root);
    }
};

int main()
{

    BST<int> binarySearchTree;

    binarySearchTree.Insert(12);
    binarySearchTree.Insert(122);
    binarySearchTree.Insert(929);
    binarySearchTree.Insert(14);
    binarySearchTree.Insert(145);
    binarySearchTree.Insert(18);
    binarySearchTree.Insert(2);
    binarySearchTree.insertRec(1200);

    int x = binarySearchTree.getMaxRec();
    cout << x << endl;
    int y = binarySearchTree.getMinRec();
    cout << y << endl;

    x = binarySearchTree.getMax();
    cout << x << endl;
    y = binarySearchTree.getMin();
    cout << y << endl;

    cout << binarySearchTree.Height() << endl;

    binarySearchTree.inOrderTraversal();
    cout << endl;
    binarySearchTree.postOrderTraversal();
    cout << endl;
    binarySearchTree.preOrderTraversal();
    cout << endl;

    binarySearchTree.levelOrder();
    cout << "\n";

    binarySearchTree.Remove(929);
    binarySearchTree.levelOrder();

    binarySearchTree.Remove(14);
    binarySearchTree.levelOrder();
    cout << endl;

    cout << binarySearchTree.Search(12) << endl;
    cout << binarySearchTree.Search(156) << endl;
    cout << endl;

    cout << binarySearchTree.countLeaves() << endl;
    cout << binarySearchTree.countNodes() << endl;
    cout << endl;
    cout << endl;
    binarySearchTree.Clear();
}

// #End
