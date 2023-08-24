#include <bits/stdc++.h>
using namespace std;

// Given an array of integers A, every element appears twice except for one. Find that single one.
// NOTE: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

int singleNumber(const vector<int> &A)
{
    int ans = 0;

    // XOR all the elements of A
    for (auto const &i : A)
    {
        ans = ans ^ i;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << singleNumber(A) << endl;

    return 0;
}