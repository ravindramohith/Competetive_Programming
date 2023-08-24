#include <bits/stdc++.h>
using namespace std;

// Define the default capacity of a queue
#define SIZE 1000

// A class to store a queue
template <class T>
class Queue
{
    T *arr;     // array to store queue elements
    int capacity; // maximum capacity of the queue
    int front;    // front points to the front element in the queue (if any)
    int rear;     // rear points to the last element in the queue
    int count;    // current size of the queue

public:
    Queue(int size = SIZE); // constructor
    ~Queue();               // destructor

    T dequeue();
    void enqueue(T x);
    int size();
    bool isEmpty();
    bool isFull();
    void view();
};
