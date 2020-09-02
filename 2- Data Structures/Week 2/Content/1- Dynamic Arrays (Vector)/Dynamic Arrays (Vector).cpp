// Dynamic Arrays = Vectors
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

template <class Type>
class Vector
{
    // attributes.
private:
    int Size = 0, Capacity = 0;
    Type *vector;
    // methods.
public:
    Vector() : Size(0), Capacity(0), vector(NULL) {} // default constructor.

    Vector(int vectorCapacity) // parameterized constructor.
    {
        Capacity = vectorCapacity;
        Size = Size;
        vector = new Type[vectorCapacity];

        for (int i = 0; i < Capacity; i++)
        {
            vector[i] = NULL;
        }
    }

    Type getAt(int Index)
    {
        return vector[Index];
    }

    int vectorSize()
    {
        return Size;
    }

    bool isEmpty()
    {
        return (Size == 0);
    }

    void Reserve(int newCapacity)
    {
        if (Capacity > newCapacity)
            return;

        Type *temporaryVector = new Type[newCapacity];

        for (int i = 0; i < Capacity; i++)
        {
            temporaryVector[i] = vector[i];
        }

        if (vector != NULL)
            delete[] vector;

        vector = temporaryVector;
        Capacity = newCapacity;
    }

    Type &operator[](int Index)
    {
        return vector[Index];
    }

    Type Front()
    {
        return vector[0];
    }

    Type Back()
    {
        return vector[Size - 1];
    }

    void pushAt(int Index, Type Item)
    {
        Size++;
        if (Index >= Capacity)
            Reserve(Index + Capacity);
        vector[Index] = Item;
    }

    void popAt(int Index)
    {
        for (int i = Index; i < Size - 1; i++)
        {
            vector[i] = vector[i + 1];
        }
        Size--;
    }

    void Print()
    {
        cout << "[ ";
        for (int i = 0; i < Size; i++)
            if (vector[i] != NULL)
                cout << vector[i] << " ";
        cout << "]\n";
    }

    ~Vector() // destructor.
    {
        delete[] vector;
    }
};

int main()
{
    Vector<int> VECTOR(6);
    VECTOR.pushAt(0, 1);
    VECTOR.pushAt(1, 2);
    VECTOR.pushAt(2, 3);
    VECTOR.pushAt(3, 4);
    VECTOR.pushAt(4, 5);
    VECTOR.pushAt(5, 6);

    cout << VECTOR.getAt(0) << endl;
    cout << VECTOR.getAt(1) << endl;
    cout << VECTOR.getAt(2) << endl;
    VECTOR.Print();
    cout << VECTOR.vectorSize() << endl;
    VECTOR.Reserve(10);

    VECTOR.popAt(2);
    cout << VECTOR.vectorSize() << endl;
    VECTOR.Print();
    cout << VECTOR.getAt(2) << endl;

    return 0;
}
