#include <iostream>
using namespace std;

void f(int a)
{
    if (a == 0)
    {
        return;
    }
    cout << a;
    return f(a - 1); // No operation should be done at returning time
}
int main()
{
    f(3);
    return 0;
}