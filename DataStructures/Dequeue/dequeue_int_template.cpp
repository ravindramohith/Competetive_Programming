#include <bits/stdc++.h>
#include "dequeue.h"
using namespace std;

template <class T>
void Deque<T>::view()
{
    if (this->empty())
    {
        cout << "Dequeue is empty" << endl;
    }
    else
    {
        int front = this->frontIndex;
        int count = this->sizeVar;
        int rear = this->backIndex;
        int capacity = this->capacityVar;
        for (int i = front; i < front + count; i++)
        {
            cout << " --";
            T printIng = arr[i % capacity];
            while (printIng != 0)
            {
                cout << "-";
                printIng = printIng / 10;
            }
        }
        cout << " " << endl;
        for (int i = front; i < front + count; i++)
        {
            cout << "| " << arr[i % capacity] << " ";
        }
        cout << "|" << endl;
        for (int i = front; i < front + count; i++)
        {
            cout << " --";
            T printIng = arr[i % capacity];
            while (printIng != 0)
            {
                cout << "-";
                printIng = printIng / 10;
            }
        }
        cout << " " << endl;
        cout << "Front Element of the Dequeue is " << arr[front % capacity] << " & Last Element of the Dequeue is " << arr[rear % capacity] << endl;
    }
}

template class Deque<int>;
