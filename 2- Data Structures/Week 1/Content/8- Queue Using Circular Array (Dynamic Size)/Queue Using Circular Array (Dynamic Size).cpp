#include <iostream>
#include <string.h>
using namespace std;

template <class Type>
class Queue
{
    //attributes.
private:
    // we need to know two positions.
    int Front, Rear;   // Front : first, beginning, start          Rear: last, end, back.
    int numberOfItems; // to know how many items in the Queue.
    Type *quEue;       // our Queue.
    int queueSize;

    //methods.
public:
    // Default Constructor.
    Queue(int queueSize) : Front(0), Rear(queueSize - 1), numberOfItems(0)
    {
        this->queueSize = queueSize;
        quEue = new Type[queueSize]; // we create a new dynamic Queue.
    }

    // a function to Check if the Queue is empty.
    bool isEmpty()
    {
        return numberOfItems == 0;
    }

    // a function to Check if the Queue is full.
    bool isFull()
    {
        return numberOfItems == queueSize;
    }

    // a function to add items to the Queue.
    void enQueue(Type addedItem)
    {

        // we need to check if the Queue is full.
        if (isFull())
            cout << "you can't add any items!\n";

        // if the Queue is not full, we can add items.
        else
        {
            Rear = (Rear + 1) % queueSize; // to have a circular Queue.
            quEue[Rear] = addedItem;
            numberOfItems += 1; // to increase the number of items in the Queue.
        }
    }

    // a function to remove items from the Queue.
    void deQueue()
    {

        // we need to check if the Queue is empty.
        if (isEmpty())
            cout << "you can't remove any items!\n";

        // if the Queue is not empty, we can remove items.
        else
        {
            Front = (Front + 1) % queueSize; // to move "Front" to the next item's position.
            numberOfItems -= 1;              // to decrease the number of items in the Queue.
        }
    }

    // a function to get the first item in the Queue.
    Type getFront()
    {
        if (!isEmpty())
            return quEue[Front];
    }

    // a function to get the last item in the Queue.
    Type getRear()
    {
        return quEue[Rear];
    }

    // to print the items of the Queue.
    void printQueue()
    {
        cout << "Queue items : [ ";
        if (!isEmpty())
        {

            // as a circular Queue.
            for (int i = Front; i != Rear; i = (i + 1) % queueSize)
            {
                cout << quEue[i] << " ";
            }
            cout << quEue[Rear];
            cout << "]\n";
        }
    }

    // a function to search for item's position.
    int itemPosition(Type requiredItem)
    {

        int itemPosition = -1;

        if (!isEmpty())
        {

            // as a circular Queue.
            for (int i = Front; i != Rear; i = (i + 1) % queueSize)
            {
                if ((quEue[i] == requiredItem))
                {
                    itemPosition = i;
                    break;
                }
            }

            // for the last item.
            if (itemPosition == -1)
            {
                ((quEue[Rear] == requiredItem) ? itemPosition = Rear : itemPosition = itemPosition);
            }
        }

        else
            cout << "The Queue is empty!\n";

        return (itemPosition == -1) ? -1 : itemPosition - 1;
    }
};

int main()
{
    Queue<int> queuE(5);

    queuE.enQueue(10);
    queuE.enQueue(12);
    queuE.enQueue(123);
    queuE.enQueue(125);
    queuE.enQueue(126);
    queuE.printQueue();

    queuE.deQueue();
    queuE.printQueue();

    cout << queuE.getFront() << endl;
    cout << queuE.getRear() << endl;

    cout << queuE.isEmpty() << endl;
    cout << queuE.isFull() << endl;

    queuE.enQueue(1125);
    queuE.printQueue();
    cout << queuE.isFull() << endl;
    queuE.enQueue(1125);

    cout << queuE.itemPosition(10) << endl;
    cout << queuE.itemPosition(12) << endl;
    cout << queuE.itemPosition(123) << endl;
    cout << queuE.itemPosition(125) << endl;
    cout << queuE.itemPosition(126) << endl;

    queuE.deQueue();
    queuE.printQueue();
    queuE.enQueue(120);
    queuE.printQueue();
}
