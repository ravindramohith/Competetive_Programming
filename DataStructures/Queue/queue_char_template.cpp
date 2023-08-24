#include <bits/stdc++.h>
#include "queue.h"
using namespace std;
// Constructor to initialize a queue

template <class T>
Queue<T>::Queue(int size)
{
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
template <class T>
Queue<T>::~Queue()
{
    delete[] arr;
}

// Utility function to dequeue the front element
template <class T>
T Queue<T>::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    T x = arr[front];
    cout << "Removed " << x << endl;

    front = (front + 1) % capacity;
    count--;
    if (isEmpty())
    {
        cout << "Now, the Queue is empty" << endl;
    }
    return x;
}

// Utility function to add an item to the queue
template <class T>
void Queue<T>::enqueue(T item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Queue Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserted " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
    if (isFull())
    {
        cout << "Now, the Queue has been filled" << endl;
    }
}

// Utility function to return the size of the queue
template <class T>
int Queue<T>::size()
{
    return count;
}

// Utility function to check if the queue is empty or not
template <class T>
bool Queue<T>::isEmpty()
{
    return (size() == 0);
}

// Utility function to check if the queue is full or not
template <class T>
bool Queue<T>::isFull()
{
    return (size() == capacity);
}

template <class T>
void Queue<T>::view()
{
    if (this->isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        for (int i = front; i < front + count; i++)
        {
            cout << " ---";
        }
        cout << " " << endl;
        for (int i = front; i < front + count; i++)
        {
            cout << "| " << arr[i % capacity] << " ";
        }
        cout << "|" << endl;
        for (int i = front; i < front + count; i++)
        {
            cout << " ---";
        }
        cout << " " << endl;
        cout << "Front Element of the Queue is " << arr[front % capacity] << " & Last Element of the Queue is " << arr[rear % capacity] << endl;
    }
}

template class Queue<char>;
