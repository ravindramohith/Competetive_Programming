#include <bits/stdc++.h>
using namespace std;

int solve(int A)
{
    if (A == 0)
    {
        return 0;
    }

    int bitPos = 0;

    while ((1 << bitPos) <= A)
    {
        bitPos++;
    }
    bitPos--;

    int count = (bitPos * (1LL << (bitPos - 1))) % 1000000007;
    count = (count + (A + 1 - (1 << bitPos))) % 1000000007;

    return (count + solve(A - (1 << bitPos))) % 1000000007;
}

int main()
{
    cout << solve(1000000000);

    return 0;
}