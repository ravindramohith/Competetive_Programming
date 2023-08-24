#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A)
{
    vector<int> arr;
    for (int i = 0; i < A.size(); i++)
    {
        arr.push_back(A[i]);
    }
    int i = 0;
    while (arr[i] != -1)
    {
        int k = arr[i];
        arr[i] = -1;
        i = k;
    }
    return i;
}

int removeDuplicates(vector<int> &A)
{
    set<int> B = set(A.begin(), A.end());
    return B.size();

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    cout << removeDuplicates(A) << endl;

    return 0;
}