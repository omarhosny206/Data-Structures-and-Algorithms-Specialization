#include <iostream>

using namespace std;

template <class Type>

class linkedList
{
    // attributes.
private:
    struct Node
    {
        Node *Next; // " Next " means What does the Node point to?.
        Type item;  // " item " is the value of the Node.
    };

    // Head points to "Node", but first " Node "
    Node *Head;

    // Tail points to "Node", but last " Node "
    Node *Tail;

    // to know the length Of Nodes and the position.
    int lengthOfNodes;

    // methods.
public:
    linkedList() : Head(NULL), Tail(NULL), lengthOfNodes(0) {} // default Constructor.

    // to check if the linkedList is empty.
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

        newNode->item = addedItem; // ( newNode ) will get the value of the addedItem.

        // if the linkedList is empty.
        if (isEmpty())
        {
            Head = Tail = newNode;
            newNode->Next = NULL;
        }

        else
        {
            newNode->Next = Head;
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

        // if the linkedList is empty.
        if (isEmpty())
        {
            Head = Tail = newNode;
            newNode->Next = NULL;
        }

        else
        {
            Tail->Next = newNode;
            newNode->Next = NULL;
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

        // if the linkedList is empty.
        if (!position)
            insertFirst(addedItem);

        else if (position == lengthOfNodes - 1)
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
            currentNode->Next = newNode;
        }

        lengthOfNodes++;
    }

    // to remove an item from first.
    void removeFirst()
    {
        Node *temporaryNode = Head;

        // if the Linked List is empty.
        if (isEmpty())
            return;

        else
        {
            Head = Head->Next;
            temporaryNode->Next = NULL;
            delete temporaryNode;
            lengthOfNodes--;
        }
    }

    // to remove an item from last.
    void removeLast()
    {

        Node *currentNode = Head->Next;
        Node *previousNode = Head;

        // if the Linked List is empty.
        if (isEmpty())
            return;

        else
        {
            while (currentNode != Tail)
            {
                previousNode = currentNode;
                currentNode = currentNode->Next;
            }

            delete currentNode;
            previousNode->Next = NULL;
            Tail = previousNode;
            lengthOfNodes--;
        }
    }

    // to remove an item from any position.
    void removeAtPosition(Type position)
    {

        Node *currentNode = Head->Next;
        ;
        Node *previousNode = Head;

        if (isEmpty())
            return;

        if (!position)
            removeFirst();

        else if (position == lengthOfNodes - 1)
            removeLast();

        else
        {
            for (int i = 1; i < position; i++)
            {
                previousNode = currentNode;
                currentNode = currentNode->Next;
            }

            previousNode->Next = currentNode->Next;
            delete currentNode;
            lengthOfNodes--;
        }
    }

    // to remove an item from any item.
    void removeItem(Type givenItem)
    {
        // "for loop" till finiding the position which is the previous position of the required one.
        Node *currentNode = Head->Next;
        Node *previousNode = Head;

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
                previousNode = currentNode;
                currentNode = currentNode->Next;
            }

            previousNode->Next = currentNode->Next;
            delete currentNode;
            lengthOfNodes--;
        }
    }

    // to reverse the Linked List.
    void reverseLinkedList()
    {

        // check if the Linked List is empty.
        if (isEmpty())
            return;

        else
        {

            Tail = Head;                        // it is normal when you reverse a Linked list to make " Tail == Head ".
            Node *currentNode = Head;           // to be at the first Node (Head)
            Node *previousNode = NULL;          // to be at the previousNode of the currentNode.
            Node *nextNode = currentNode->Next; // to connect with the next Node of currentNode.

            while (nextNode != NULL && currentNode != NULL)
            {

                nextNode = currentNode->Next;

                currentNode->Next = previousNode;

                previousNode = currentNode;

                currentNode = nextNode;
            }

            Head = previousNode;
        }
    }

    // to search for Item.
    int searchItem(Type requiredItem)
    {

        Node *currentNode = Head;
        int itemPosition = 0;

        while (currentNode != NULL)
        {

            if (currentNode->item == requiredItem)
                return itemPosition;

            currentNode = currentNode->Next;
            itemPosition++;
        }
        return -1;
    }

    // to print the Linked List.
    void printLinkedList()
    {

        Node *currentNode = Head;

        cout << "Linked List Items : [ ";
        while (currentNode != NULL)
        {
            cout << currentNode->item << " ";
            currentNode = currentNode->Next;
        }
        cout << "]\n";
    }
};

int main()
{
    linkedList<int> LinkedList;
    LinkedList.printLinkedList();
    LinkedList.insertFirst(10);
    LinkedList.printLinkedList();
    LinkedList.insertLast(12);
    LinkedList.printLinkedList();
    LinkedList.insertFirst(23);
    LinkedList.printLinkedList();
    LinkedList.insertFirst(3);
    LinkedList.printLinkedList();
    LinkedList.insertAtPosition(1800, 3);
    LinkedList.printLinkedList();
    LinkedList.reverseLinkedList();
    LinkedList.printLinkedList();

    cout << "at position : " << LinkedList.searchItem(5) << endl;

    cout << "\n\n\n";

    LinkedList.removeFirst();
    LinkedList.printLinkedList();
    LinkedList.removeLast();
    LinkedList.printLinkedList();
    LinkedList.removeAtPosition(1);
    LinkedList.printLinkedList();
    LinkedList.insertFirst(1528);
    LinkedList.printLinkedList();
    LinkedList.insertFirst(312);
    LinkedList.printLinkedList();

    LinkedList.removeItem(23);
    LinkedList.printLinkedList();
    LinkedList.removeItem(312);
    LinkedList.printLinkedList();

    LinkedList.insertFirst(312);
    LinkedList.printLinkedList();

    LinkedList.reverseLinkedList();
    LinkedList.printLinkedList();

    cout << endl
         << endl;

    linkedList<int> Linkedlist;
    Linkedlist.insertFirst(10);
    Linkedlist.printLinkedList();
    Linkedlist.removeFirst();
    Linkedlist.printLinkedList();
}
