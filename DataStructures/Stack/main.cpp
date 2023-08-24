#include <bits/stdc++.h>
#include "Stack.h"
using namespace std;

// Driver program to test above functions
int main()
{
    Stack stack;
    while (true)
    {
        int input;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. View Current Stack" << endl;
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
            int number;
            cout << "Enter number to be pushed: ";
            cin >> number;
            stack.push(number);
        }
        else if (input == 2)
        {
            stack.pop();
        }
        else if (input == 3)
        {
            stack.view();
        }
        else if (input == 4)
        {
            break;
        }
    }

    return 0;
}