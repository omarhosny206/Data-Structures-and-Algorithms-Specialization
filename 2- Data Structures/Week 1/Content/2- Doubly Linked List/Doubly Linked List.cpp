#include <iostream>
using namespace std;

template <class Type>
class doublyLinkedList
{
    // attributes.
private:
    struct Node
    {
        Node *Next;     // " Next " means What does the Node point to? (forward direction).
        Node *Previous; // " Previous " means What does the Node point to? (reverse direction).
        Type item;      // " item " is the value of the Node.
    };

    // Head points to "Node", but first " Node "
    Node *Head;

    // Tail points to "Node", but last " Node "
    Node *Tail;

    // to know the lengthOfNodes and the position.
    int lengthOfNodes;

    // methods.
public:
    doublyLinkedList() : Head(NULL), Tail(NULL), lengthOfNodes(0) {} // default Constructor.

    // to check if the doublyLinkedList is empty.
    bool isEmpty()
    {
        return Head == NULL;
        // **Note we can make it like : return lengthOfNodes==0;
    }

    // to add items from first.
    void insertFirst(Type addedItem)
    {

        // we need to create a new Node.
        Node *newNode = new Node;

        newNode->item = addedItem; // (new Node ) will get the value of the addedItem.

        // if the doublyLinkedList is empty.
        if (isEmpty())
        {
            Head = Tail = newNode;
            newNode->Next = newNode->Previous = NULL;
        }

        else
        {

            newNode->Next = Head;

            newNode->Previous = NULL;

            Head->Previous = newNode;

            Head = newNode;
        }

        lengthOfNodes++;
    }

    // to add items from last.
    void insertLast(Type addedItem)
    {

        // we need to create a new Node.
        Node *newNode = new Node;

        newNode->item = addedItem; // (new Node ) will get the value of the addedItem.

        // if the doublyLinkedList is empty.
        if (isEmpty())
        {
            Head = Tail = newNode;
            newNode->Next = newNode->Previous = NULL;
        }

        else
        {

            newNode->Previous = Tail;

            newNode->Next = NULL;

            Tail->Next = newNode;

            Tail = newNode;
        }

        lengthOfNodes++;
    }

    // to add items from any position.
    void insertAtPosition(Type addedItem, Type position)
    {

        // we need to create a new Node.
        Node *newNode = new Node;

        newNode->item = addedItem; // (new Node ) will get the value of the addedItem.

        // if the doublyLinkedList is empty.
        if (!position)
            insertFirst(addedItem);

        else if (position == lengthOfNodes)
            insertLast(addedItem);

        else
        {

            Node *currentNode = Head;

            for (int i = 1; i < position; i++)
            {
                // "for loop" till finiding the position which is the previous position of the required one.
                currentNode = currentNode->Next;
            }

            newNode->Next = currentNode->Next;
            newNode->Previous = currentNode;
            currentNode->Next->Previous = newNode;
            currentNode->Next = newNode;
        }

        lengthOfNodes++;
    }

    // to remove an item from first.
    void removeFirst()
    {

        Node *temporaryNode = Head;

        // if the doublyLinkedList is empty.
        if (isEmpty())
            return;

        else
        {

            Head = Head->Next;
            Head->Previous = NULL;
            temporaryNode->Next = temporaryNode->Previous = NULL;
            delete temporaryNode;
            lengthOfNodes--;
        }
    }

    // to remove an item from last.
    void removeLast()
    {

        Node *temporaryNode = Tail;

        // if the doublyLinkedList is empty.
        if (isEmpty())
            return;

        else
        {

            Tail = Tail->Previous;
            Tail->Next = NULL;
            temporaryNode->Previous = NULL;
            delete temporaryNode;
            lengthOfNodes--;
        }
    }

    // to remove an item from any position.
    void removeAtPosition(Type position)
    {

        Node *currentNode = Head->Next;

        if (isEmpty())
            return;

        if (!position)
            removeFirst();

        else if (position == lengthOfNodes)
            removeLast();

        else
        {

            for (int i = 1; i < position; i++)
            {

                currentNode = currentNode->Next;
            }

            currentNode->Previous->Next = currentNode->Next;

            currentNode->Next->Previous = currentNode->Previous;

            currentNode->Next = currentNode->Previous = NULL;

            delete currentNode;

            lengthOfNodes--;
        }
    }

    // to remove an item.
    void removeItem(Type givenItem)
    {

        Node *currentNode = Head->Next;

        if (isEmpty())
            return;

        if (Head->item == givenItem)
            removeFirst();

        else if (Tail->item == givenItem)
            removeLast();

        else
        {

            while (currentNode->item != givenItem)
            {

                currentNode = currentNode->Next;
            }

            // if it is not found.
            if (currentNode == NULL)
                cout << "not found!\n";

            else
            {

                currentNode->Previous->Next = currentNode->Next;

                currentNode->Next->Previous = currentNode->Previous;

                currentNode->Next = currentNode->Previous = NULL;

                delete currentNode;

                lengthOfNodes--;
            }
        }
    }

    // to print the doublyLinkedList.
    void printDoublyLinkedList()
    {

        Node *currentNode = Head;

        cout << " doubleLinkedList Items : [ ";
        while (currentNode != NULL)
        {
            cout << currentNode->item << " ";
            currentNode = currentNode->Next;
        }
        cout << "]\n";
    }

    // to print the doublyLinkedList reversely.
    void printReverseDoublyLinkedList()
    {

        Node *currentNode = Tail;

        cout << " reverse doubleLinkedList Items : [ ";
        while (currentNode != NULL)
        {
            cout << currentNode->item << " ";
            currentNode = currentNode->Previous;
        }
        cout << "]\n";
    }
};

int main()
{

    doublyLinkedList<int> DoublyLinkedList;

    DoublyLinkedList.insertFirst(12);
    DoublyLinkedList.insertFirst(15);

    DoublyLinkedList.printDoublyLinkedList();
    DoublyLinkedList.printReverseDoublyLinkedList();

    DoublyLinkedList.insertLast(115);
    DoublyLinkedList.insertLast(150);

    DoublyLinkedList.printDoublyLinkedList();
    DoublyLinkedList.printReverseDoublyLinkedList();

    DoublyLinkedList.insertAtPosition(250, 2);
    DoublyLinkedList.printDoublyLinkedList();
    DoublyLinkedList.printReverseDoublyLinkedList();

    cout << "\n\n\n"
        << endl;

    DoublyLinkedList.removeFirst();
    DoublyLinkedList.removeLast();
    DoublyLinkedList.removeItem(250);
    DoublyLinkedList.printDoublyLinkedList();
    DoublyLinkedList.printReverseDoublyLinkedList();

    cout << "\n\n\n"
        << endl;

    DoublyLinkedList.insertFirst(1512);
    DoublyLinkedList.insertFirst(15);
    DoublyLinkedList.printDoublyLinkedList();
    DoublyLinkedList.printReverseDoublyLinkedList();
    cout << "\n";
    DoublyLinkedList.removeAtPosition(2);
    DoublyLinkedList.printDoublyLinkedList();
    DoublyLinkedList.printReverseDoublyLinkedList();
}
