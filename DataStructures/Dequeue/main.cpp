#include <bits/stdc++.h>
#include "dequeue.h"
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of Dequeue: ";
    cin >> size;
    Deque<int> *dequeue;
    dequeue = new Deque<int>();
    while (true)
    {
        int input;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. View Current Dequeue" << endl;
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
            while (true)
            {
                cout << "1. Push Front" << endl;
                cout << "2. Push Back" << endl;
                cout << "3. Go Back" << endl;
                int Inp;
                cout << "Enter command(1/2/3): ";
                cin >> Inp;
                if ((Inp != 1 && Inp != 2) && (Inp != 3))
                {
                    cout << "Wrong input, Enter either 1 or 2 or 3 as an input" << endl;
                    continue;
                }
                if (Inp == 1)
                {
                    int item;
                    cout << "Enter item to be enqueued at front: ";
                    cin >> item;
                    dequeue->push_front(item);
                }
                else if (Inp == 2)
                {
                    int item;
                    cout << "Enter item to be enqueued at back: ";
                    cin >> item;
                    dequeue->push_back(item);
                }
                else if (Inp == 3)
                {
                    break;
                }
            }
        }
        else if (input == 2)
        {
            while (true)
            {
                cout << "1. Pop Front" << endl;
                cout << "2. Pop Back" << endl;
                cout << "3. Go Back" << endl;
                int Inp;
                cout << "Enter command(1/2/3): ";
                cin >> Inp;
                if ((Inp != 1 && Inp != 2) && (Inp != 3))
                {
                    cout << "Wrong input, Enter either 1 or 2 or 3 as an input" << endl;
                    continue;
                }
                if (Inp == 1)
                {
                    dequeue->pop_front();
                }
                else if (Inp == 2)
                {
                    dequeue->pop_back();
                }
                else if (Inp == 3)
                {
                    break;
                }
            }
        }
        else if (input == 3)
        {
            dequeue->view();
        }
        else if (input == 4)
        {
            break;
        }
    }

    return 0;
}
