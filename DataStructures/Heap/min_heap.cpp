#include "min_heap.h"
#include <algorithm>

MinHeap::MinHeap()
{
    heap.push_back(-1); // Dummy element to make 1-based indexing work
}

void MinHeap::insert(int num)
{
    heap.push_back(num);
    shift_up(heap.size() - 1);
}

int MinHeap::remove()
{
    if (heap.size() <= 1)
    {
        return -1; // Heap is empty
    }
    int root = heap[1];
    if (heap.size() > 2)
    {
        heap[1] = heap.back();
        heap.pop_back();
        shift_down(1);
    }
    else
    {
        heap.pop_back();
    }
    return root;
}

std::vector<int> MinHeap::sort() const
{
    std::vector<int> result;
    MinHeap tmp = *this;
    while (!tmp.empty())
    {
        result.push_back(tmp.remove());
    }
    return result;
}

bool MinHeap::empty() const
{
    return heap.size() <= 1;
}

int MinHeap::size() const
{
    return heap.size() - 1;
}

void MinHeap::heapify(int i)
{
    shift_down(i);
}

void MinHeap::shift_up(int i)
{
    while (i > 1)
    {
        int parent = i / 2;
        if (heap[parent] <= heap[i])
        {
            break;
        }
        std::swap(heap[parent], heap[i]);
        i = parent;
    }
}

void MinHeap::shift_down(int i)
{
    while (2 * i < heap.size())
    {
        int left_child = 2 * i;
        int right_child = 2 * i + 1;
        int smallest_child = left_child;
        if (right_child < heap.size() && heap[right_child] < heap[left_child])
        {
            smallest_child = right_child;
        }
        if (heap[i] <= heap[smallest_child])
        {
            break;
        }
        std::swap(heap[i], heap[smallest_child]);
        i = smallest_child;
    }
}
