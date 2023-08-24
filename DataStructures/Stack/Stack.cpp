#include <bits/stdc++.h>
#include "Stack.h"
using namespace std;

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow\n";
        return 0;
    }
    else
    {
        int x = a[top--];
        cout << x << " Popped from stack\n";
        return x;
    }
}
int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::view()
{
    if (this->isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        for (int i = 0; i < top + 1; i++)
        {
            cout << " --";
            int printIng = a[i];
            while (printIng != 0)
            {
                cout << "-";
                printIng = printIng / 10;
            }
        }
        cout << " " << endl;
        for (int i = 0; i < top + 1; i++)
        {
            cout << "| " << a[i] << " ";
        }
        cout << "|" << endl;
        for (int i = 0; i < top + 1; i++)
        {
            cout << " --";
            int printIng = a[i];
            while (printIng != 0)
            {
                cout << "-";
                printIng = printIng / 10;
            }
        }
        cout << " " << endl;
        cout << "Top Element of the Stack is " << a[top] << endl;
    }
}
