#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>

class MinHeap
{
public:
    MinHeap();
    void insert(int num);
    int remove();
    std::vector<int> sort() const;
    bool empty() const;
    int size() const;

private:
    std::vector<int> heap;
    void heapify(int i);
    void shift_up(int i);
    void shift_down(int i);
};

#endif /* MINHEAP_H */
