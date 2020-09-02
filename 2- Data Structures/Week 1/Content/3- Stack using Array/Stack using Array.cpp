#include <iostream>
#include <string>
using namespace std;

const int fixedSize = 5; // size of array.

template <class type> // For using any dataType.

class Stack
{

    //attributes
private:
    int Top; // Top will points to the top of the stack.
    type stack[fixedSize];

    //methods
public:
    Stack() : Top(-1) {} // Default Constructor.

    // A function to check if the stack is full or not.
    bool isFull()
    {
        return ((Top >= fixedSize - 1) ? 1 : 0);
    }

    // push method
    void push(type Number)
    {
        if (isFull())
            cout << "Sorry it's full, you can't add any stacks\n";
        else
        {
            ++Top;
            stack[Top] = Number;
        }
    }

    // A function to check if the stack is empty or not
    bool isEmpty()
    {
        return ((Top == -1) ? 1 : 0);
    }

    // pop method
    void pop()
    { // you can't get the removed stack.
        if (isEmpty())
            cout << "Sorry it's empty, you can't  remove any stacks\n";
        else
            --Top;
    }

    //    // pop method
    //    void pop (int& Number) {     // you can get the removed stack.
    //        if (isEmpty())
    //            cout<<"Sorry it's empty, you can't  remove any stacks\n";
    //        else{
    //            Number = stack[Top];
    //            --Top;}
    //    }

    // to get the top of the stack.
    type getTop()
    {
        return stack[Top];
    }

    // print method
    void printStack()
    {
        cout << "[ ";
        for (int i = Top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << "]\n";
    }
};

int main()
{
    Stack<double> STACK;
    STACK.push(10.111);
    STACK.push(22.2);
    STACK.pop();

    cout << STACK.getTop() << endl;

    cout << "isEmpty = " << STACK.isEmpty() << endl;
    cout << "isFull = " << STACK.isFull() << endl;

    STACK.printStack();
}
