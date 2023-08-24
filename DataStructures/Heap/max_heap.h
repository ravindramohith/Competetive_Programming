#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

using namespace std;

class MaxHeap
{
private:
    vector<int> heap;
    void heapifyUp(int idx);
    void heapifyDown(int idx);
    void buildHeap();

public:
    MaxHeap();
    MaxHeap(const vector<int> &arr);
    void insert(int val);
    int extractMax();
    int getMax() const;
    int size() const;
    bool empty() const;
};

#endif /* MAXHEAP_H */
