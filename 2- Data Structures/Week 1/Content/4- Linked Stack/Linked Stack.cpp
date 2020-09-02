#include <iostream>
#include <string.h>

using namespace std;

template<class Type>

class Stack {

    //attributes
private:
    struct Node {
        Node *Next; // " Next " means What does the Node point to?.
        Type item;  // " item " is the value of the Node's item.
    };

    // Top points to "Node"
    Node *Top;
    // currentNode for printing and determining each Node.
    Node *currentNode;

    // methods
public:
    // at first, "Top" doesn't point at any thing.
    Stack() : Top(NULL) {} // default Constructor.

    // push method
    void push(Type pushedItem) {

        Node *newNode = new Node; // To create a newNode beside lastNode.
        if (newNode == NULL)
            cout << "You can't push any items\n";
        else {
            newNode->item = pushedItem; // (new Node ) will get the value of the pushedItem.
            newNode->Next = Top;        // To connect  (new Node) with (previous Node), (new Node) points to (Top) .

            // (Top) points to (new Node)
            Top = newNode; // Top will get the last position of the new Node .
        }
    }

    // A function to check if the stack is empty or not
    bool isEmpty() {
        return ((Top == NULL) ? 1 : 0);
    }

    // pop method
    void pop() { // you can't get the removed item.
        if (isEmpty())
            cout << "you can't  remove any items\n";
        else {
            Node *temporaryNode = new Node; // temporaryNode is made to save the other Nodes.
            temporaryNode = Top;            // Top is the position of the latest node (new Node)

            // (Top) points to (previous Node)
            //  (Top) points to "the Next" of (new Node = Top)
            Top = Top->Next; // "Next" still have the position of the previous Nodes

            // We need to delete "temporaryNode"
            temporaryNode = temporaryNode->Next = NULL;
            delete temporaryNode;
        }
    }

    // pop method
    void pop(Type &topValue) { // you can get the removed item.
        if (isEmpty())
            cout << "you can't  remove any items\n";
        else {
            topValue = Top->item;
            Node *temporaryNode = new Node; // temporaryNode is made to
            temporaryNode = Top;            // Top is the position of the latest node "newNode"
            // Now we can move Top to the previousNode
            Top = Top->Next; // "Next" still have the last position of the previous Nodes.
            // We need to delete "temporaryNode"
            temporaryNode = temporaryNode->Next = NULL;
            delete temporaryNode;
        }
    }

    // to get the top of the stack.
    Type getTop() {
        return Top->item;
    }

    // print method
    void printStack() {
        currentNode = Top; // currentNode will take the position of  Top
        cout << "[ ";

        // We need a while loop to get all the Nodes.
        while (currentNode != NULL) {
            cout << currentNode->item; // To print the value
            cout << " ";
            currentNode = currentNode->Next; // To move to the previous Node.
        }
        cout << "]\n";
    }
};

int main() {
    Stack<int> STACK;

    STACK.push(10);
    STACK.push(17);

    STACK.pop();

    int x = 1;
    STACK.pop(x);
    cout << x << endl; // we get the removed value "10".

    STACK.printStack();

    STACK.push(2590);
    cout << STACK.getTop() << endl;
    STACK.printStack();

    Stack<char> StacK;
    StacK.push('o');
    StacK.push('k');

    StacK.pop();

    StacK.printStack();

    Stack<string> stacK;
    stacK.push("helloWorld");
    stacK.push("that's me");

    stacK.pop();

    stacK.printStack();
}

//# DONE
