// Queue : is a linear structure which follows a particular order.
// The order is First In First Out (FIFO).
// A good example of a queue is any queue of consumers for a resource where the consumer that came first is served first
// The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.

#include <iostream>
using namespace std;

template <class Type>
class Queue
{
    //attributes.
private:
    struct Node
    {
        Node *Next; // " Next " means What does the Node point to?.
        Type item;  // " item " is the value of the Node's item.
    };

    // to control the Queue.
    Node *Front; // to point for the first Node.
    Node *Rear;  // to point for the last Node.

    // to print or delete items.
    Node *currentNode;

    // to know the number of the items.
    int numberOfItems;

    //methods
public:
    // default Constructor.
    Queue() : Front(NULL), Rear(NULL), numberOfItems(0) {}

    // check if the Queue is empty.
    bool isEmpty()
    {
        return numberOfItems == 0;
    }

    // a function to add items.
    void enQueue(Type addedItem)
    {

        // we need to create a new Node beside lastNode.
        Node *newNode = new Node;

        newNode->item = addedItem;
        newNode->Next = NULL; // (New Node) will always point to "NULL", because it is "SLAVE"

        // if there are no Nodes.
        if (isEmpty())
        {
            Rear = Front = newNode; // the new Node is the same as Front, Rear Node.
        }

        // if there are Nodes before.
        else
        {
            // to make this new Node connected to the previous Nodes.
            Rear->Next = newNode; // to connect with (next Node) we need to to connect (previous Node) , then (Rear's position will change to the new Node, so we need to connect with previous Node).
            Rear = newNode;       // the last item's position becomes the new Node.
        }

        numberOfItems += 1; // to increase the number of items.
    }

    // another function to add items.
    //    void enQueue ( Type addedItem ){
    //
    //        if (!isEmpty()){
    //                // we need to create a new Node
    //                Node* newNode = new Node;
    //                newNode->item = addedItem;
    //                newNode->Next = NULL;
    //
    //               // to make this Node connected to the previous Nodes.
    //               Rear->Next = newNode;                // the last item's Next points to the new Node.
    //               Rear = newNode;                              // the last item's position becomes the new Node.
    //
    //               numberOfItems +=1;                       // to increase the number of items.
    //        }
    //
    //        else {
    //            Front = new Node;                   // there are no Nodes, we need to create the first Node to make " Front " point at it.
    //            Front->item = addedItem;
    //            Front->Next = NULL;            // because there aren't another Node.
    //            Rear = Front;                           // they point at the same item at the beginning.
    //            numberOfItems +=1;                       // to increase the number of items.
    //        }
    //    }

    // a function to remove items from the Queue.
    void deQueue()
    {

        // if the Queue is empty.
        if (isEmpty())
            cout << "you can't remove items!\n";

        else
        {

            // if we have only one Node.
            if (Front == Rear)
            {
                Front = NULL; // to delete Front.
                Rear = NULL;  // to delete Rear.
            }

            // if we have more than one Node.
            else
            {
                // we need to create a temporaryNode Node to point the Front.
                Node *temporaryNode = Front;

                // (Front) needs to point to ( next Node = removedNode's Next)
                Front = Front->Next;
                temporaryNode->Next = NULL;
                numberOfItems -= 1;
                delete temporaryNode;
            }
        }
    }

    // a function to get the first item in the Queue.
    Type getFront()
    {
        if (!isEmpty())
            return Front->item;
    }

    // a function to get the last item in the Queue.
    Type getRear()
    {
        if (!isEmpty())
            return Rear->item;
    }

    // to delete all the items.
    void deleteItems()
    {
        while (Front != NULL)
        {
            currentNode = Front;
            Front = Front->Next;
            delete currentNode;
        }
        Rear = NULL;
        numberOfItems = 0;
    }

    // to print the items inside the Queue.
    void printQueue()
    {
        currentNode = Front;

        cout << "Queue items : [ ";
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
    Queue<int> queuE;
    queuE.enQueue(10);
    queuE.enQueue(12);
    queuE.printQueue();
    cout << queuE.getFront() << endl;
    cout << queuE.getRear() << endl;
    queuE.deQueue();
    queuE.printQueue();
    queuE.enQueue(10);
    queuE.printQueue();
    queuE.enQueue(1);
    queuE.enQueue(2);
    queuE.enQueue(3);
    queuE.enQueue(5);
    queuE.enQueue(4);
    queuE.printQueue();
    queuE.enQueue(51);
    queuE.enQueue(2);
    queuE.enQueue(36);
    queuE.enQueue(55);
    queuE.enQueue(44);
    queuE.printQueue();

    queuE.deleteItems();
    queuE.printQueue();
}
