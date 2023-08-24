#include <iostream>
using namespace std;

void f(int a)
{
    if (a > 0)
    {
        cout << a;
        f(a - 1); 
        f(a - 1); 
    }
}
int main()
{
    f(5);
    return 0;
}