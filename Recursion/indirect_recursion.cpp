#include <iostream>
using namespace std;

void B(int a); // declare to avoid reading errors

void A(int a)
{
    if (a > 0)
    {
        cout << a;
        B(a - 1);
    }
}
void B(int a)
{
    if (a > 1)
    {
        cout << a;
        A(a / 2);
    }
}
int main()
{
    A(20);
    return 0;
}