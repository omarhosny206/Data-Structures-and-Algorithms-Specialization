#include <iostream>
#include <string.h>
using namespace std;

const int queueSize = 5;
template <class Type>
class Queue
{
    //attributes.
private:
    // we need to know two positions.
    int Front, Rear;       // Front : first, beginning, start          Rear: last, end, back.
    int numberOfItems;     // to know how many items in the Queue.
    Type quEue[queueSize]; // our Queue.

    //methods.
public:
    // Default Constructor.
    Queue() : Front(0), Rear(queueSize - 1), numberOfItems(0) {}

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
};

int main()
{
    Queue<int> queuE;
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
}
