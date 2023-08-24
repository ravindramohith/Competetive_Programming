#include <iostream>
using namespace std;

// template <class>
class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array(int s = 10)
    {
        size = s;
        A = new int[size];
        length = 0;
    }
    ~Array()
    {
        delete[] A;
        A = NULL;
    }
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
};

void Array::Display()
{
    for (int i = 0; i < size + 1; i++)
    {
        cout << " --";
        int printIng = A[i];
        if (printIng == 0)
        {
            cout << "-";
        }
        else
        {
            while (printIng != 0)
            {
                cout << "-";
                printIng = printIng / 10;
            }
        }
    }
    cout << " " << endl;
    for (int i = 0; i < size + 1; i++)
    {
        cout << "| " << A[i] << " ";
    }
    cout << "|" << endl;
    for (int i = 0; i < size + 1; i++)
    {
        cout << " --";
        int printIng = A[i];
        if (printIng == 0)
        {
            cout << "-";
        }
        else
        {
            while (printIng != 0)
            {
                cout << "-";
                printIng = printIng / 10;
            }
        }
    }
    cout << " " << endl;
}

void Array::Insert(int index, int x)
{
    if (index >= 0)
    {
        for (int i = length - 1; i >= index; i--)
        {
            // cout << i << endl;
            A[i + 1] = A[i];
        }
        A[index] = x;
        cout << index << endl;
        length++;
    }
}

int Array::Delete(int index)
{
    int x = 0;
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    return x;
}
int main(int argc, const char *argv[])
{
    Array a(12);
    a.Insert(0, 1);
    a.Insert(1, 20);
    // a.I
    a.Insert(3, 40);
    // a.Insert(3,50);
    a.Display();
    return 0;
}