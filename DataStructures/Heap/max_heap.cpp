#include "max_heap.h"

MaxHeap::MaxHeap()
{
    heap.push_back(-1); // -1 as a placeholder for the root element
}

MaxHeap::MaxHeap(const vector<int> &arr)
{
    heap.push_back(-1); // -1 as a placeholder for the root element
    for (int i = 0; i < arr.size(); i++)
    {
        insert(arr[i]);
    }
}

void MaxHeap::insert(int val)
{
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}

int MaxHeap::extractMax()
{
    if (heap.size() == 1)
    {
        throw "Heap is empty";
    }
    int maxVal = heap[1];
    heap[1] = heap.back();
    heap.pop_back();
    heapifyDown(1);
    return maxVal;
}

int MaxHeap::getMax() const
{
    if (heap.size() == 1)
    {
        throw "Heap is empty";
    }
    return heap[1];
}

int MaxHeap::size() const
{
    return heap.size() - 1;
}

bool MaxHeap::empty() const
{
    return heap.size() == 1;
}

void MaxHeap::heapifyUp(int idx)
{
    while (idx > 1 && heap[idx] > heap[idx / 2])
    {
        swap(heap[idx], heap[idx / 2]);
        idx /= 2;
    }
}

void MaxHeap::heapifyDown(int idx)
{
    int leftChild = idx * 2;
    int rightChild = idx * 2 + 1;
    int largest = idx;
    if (leftChild < heap.size() && heap[leftChild] > heap[largest])
    {
        largest = leftChild;
    }
    if (rightChild < heap.size() && heap[rightChild] > heap[largest])
    {
        largest = rightChild;
    }
    if (largest != idx)
    {
        swap(heap[idx], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::buildHeap()
{
    for (int i = heap.size() / 2; i >= 1; i--)
    {
        heapifyDown(i);
    }
}
