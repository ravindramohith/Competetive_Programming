#include <iostream>
using namespace std;

void f(int a)
{
    if (a > 0)
    {
        f(a - 1); // donot perform any operation before calling.
        cout << a;
    }
}
int main()
{
    f(5);
    return 0;
}