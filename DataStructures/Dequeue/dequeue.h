#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

// Class definition of the deque
template <class X>
class Deque
{

private:
    // Stores the frontIndex
    int frontIndex;

    // Stores the backIndex
    int backIndex;

    // Stores the array
    X *arr;

    // Stores the size of deque
    int sizeVar;

    // Stores the size of array
    int capacityVar;

public:
    // Deque class constructor
    Deque(int Size = SIZE)
    {
        capacityVar = Size;
        arr = new X[capacityVar];
        frontIndex = backIndex = -1;
        sizeVar = 0;
    }

    // Function methods
    bool empty();
    bool full();
    void push_back(X x);
    void push_front(X x);
    void pop_front();
    void pop_back();
    X front();
    X back();
    int capacity();
    int size();
    void view();
};