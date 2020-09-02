#include <iostream>
#include <string.h>
using namespace std;

template <class Type>

class Stack
{

    //attributes
private:
    struct Node
    {
        Node *Next;
        Type item;
    };

    // Top points to "Node"
    Node *Top;
    // currentNode for printing
    Node *currentNode;

    // methods
public:
    Stack() : Top(NULL) {} // default Constructor.

    // push method
    void push(Type pushedItem)
    {
        Node *newNode = new Node; // To create a newNode beside lastNode.
        if (newNode == NULL)
            cout << "You can't push any items\n";
        else
        {
            newNode->item = pushedItem; // The newNode will get the value of the pushedItem.
            newNode->Next = Top;        // Next of the the newNode points to Top.
            Top = newNode;              // Top will get the last position of the newNode.
        }
    }

    // A function to check if the stack is empty or not.
    bool isEmpty()
    {
        return ((Top == NULL) ? 1 : 0);
    }

    // pop method
    void pop()
    { // you can't get the removed item.
        if (isEmpty())
            cout << "you can't  remove any items\n";
        else
        {
            Node *temporaryNode = new Node; // temporaryNode is made to save the other Nodes.
            temporaryNode = Top;            // Top is the position of the latest node "newNode"

            // Now we can move Top to the previousNode.
            Top = Top->Next; // "Next" still have the position of the previousNode, because it points to the previousNode.
            // We need to delete "temporaryNode"
            temporaryNode = temporaryNode->Next = NULL;
            delete temporaryNode;
        }
    }

    // pop method
    void pop(Type &topValue)
    { // you can get the removed item.
        if (isEmpty())
            cout << "you can't  remove any items\n";
        else
        {
            topValue = Top->item;
            Node *temporaryNode = new Node; // temporaryNode is made to save the other Nodes.
            temporaryNode = Top;            // Top is the position of the latest node "newNode"
            // Now we can move Top to the previousNode
            Top = Top->Next; // "Next" still have the last position of the previousNode
            // We need to delete "temporaryNode"
            temporaryNode = temporaryNode->Next = NULL;
            delete temporaryNode;
        }
    }

    // to get the top of the stack.
    Type getTop()
    {
        return Top->item;
    }

    // print method
    void printStack()
    {
        currentNode = Top; // currentNode will take the position of  Top
        cout << "[ ";

        // We need a while loop to get all the Nodes.
        while (currentNode != NULL)
        {
            cout << currentNode->item; // To print the value
            cout << " ";
            currentNode = currentNode->Next; // To move to the previousNode
        }
        cout << "]\n";
    }

    // Balanced Parentheses Using Stack

    // Pairs Checker
    bool arePair(Type openBracket, Type closeBracket)
    {
        if (openBracket == '{' && closeBracket == '}')
            return true;
        else if (openBracket == '(' && closeBracket == ')')
            return true;
        else if (openBracket == '[' && closeBracket == ']')
            return true;
        return false;
    }

    // Check Balanced Parentheses Using Stack
    bool checkBalanced(string Statement)
    {

        // We need a For loop to get all the characters.
        for (int i = 0; i < Statement.size(); i++)
        {

            if (Statement[i] == '(' || Statement[i] == '[' || Statement[i] == '{')
                push(Statement[i]);

            else if (Statement[i] == ')' || Statement[i] == ']' || Statement[i] == '}')
            {

                if (isEmpty() || !arePair(Top->item, Statement[i])) // EX:{4+5} ... " ({) is at Top (inside Stack) " ...  " (}) is at "i" (outside Stack) "
                    return false;
                else
                    pop();
            }
        }

        return isEmpty();
    }
};

int main()
{
    Stack<char> STACK;
    string Statement;
    cin >> Statement;
    cout << ((STACK.checkBalanced(Statement)) ? "Balanced Parentheses ...!\n" : "Not Balanced Parentheses ...!\n");
}

//# DONE