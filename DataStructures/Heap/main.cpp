#include <bits/stdc++.h>
using namespace std;
#include "max_heap.h"
#include "min_heap.h"

// Binary heap time complexity
// ╔═══════════╦══════════╦════════════╗
// ║ Algorithm ║ Average  ║ Worst Case ║
// ╠═══════════╬══════════╬════════════╣
// ║ Space     ║ O(n)     ║ O(n)       ║
// ║ Search    ║ O(n)     ║ O(n)       ║
// ║ Insert    ║ O(1)     ║ O(log n)   ║
// ║ Delete    ║ O(log n) ║ O(log n)   ║
// ║ Peek      ║ O(1)     ║ O(1)       ║
// ╚═══════════╩══════════╩════════════╝

int main()
{
    MaxHeap *maxheap = new MaxHeap();
    MinHeap *minheap = new MinHeap();
    minheap->insert(5);
    minheap->insert(3);
    minheap->insert(10);
    minheap->insert(2);
    minheap->insert(7);
    while (!minheap->empty())
    {
        std::cout << minheap->remove() << " ";
    }
    std::cout << std::endl;
    return 0;
}