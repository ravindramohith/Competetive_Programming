#include <bits/stdc++.h>
#include "queue.h"
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of Queue: ";
    cin >> size;
    Queue<int> *queue;
    queue = new Queue<int>(size);
    while (true)
    {
        int input;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. View Current Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter command(1/2/3/4): ";
        cin >> input;
        if ((input != 1 && input != 2) && (input != 3 && input != 4))
        {
            cout << "Wrong input, Enter either 1 or 2 or 3 or 4 as an input" << endl;
            continue;
        }
        if (input == 1)
        {
            int item;
            cout << "Enter item to be enqueued: ";
            cin >> item;
            queue->enqueue(item);
        }
        else if (input == 2)
        {
            queue->dequeue();
        }
        else if (input == 3)
        {
            queue->view();
        }
        else if (input == 4)
        {
            break;
        }
    }

    return 0;
}