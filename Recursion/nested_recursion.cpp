#include <iostream>
using namespace std;

int f(int a)
{
    if (a > 100)
    {
        return a - 10;
    }
    else
    {
        return f(f(a + 11));
    }
}
int main()
{
    cout << f(95);
    return 0;
}