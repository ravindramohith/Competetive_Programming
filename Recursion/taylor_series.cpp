#include <iostream>
using namespace std;

// e^x = 1+ x+ (x^2/2!)+ (x^3/3!)+....n terms
double e(int x, int n)
{
    static double power = 1, factorial = 1;
    double result;
    if (n == 0)
        return 1;
    else
    {
        result = e(x, n - 1);
        power = power * x;
        factorial = factorial * n;
        return result + (power / factorial);
    }
}
// horner's rule
double horner_e(int x, int n)
{
    static double s;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return horner_e(x, n - 1);
}

int main()
{
    cout << e(2, 10) << endl;
    cout << horner_e(2, 10) << endl;
    return 0;
}