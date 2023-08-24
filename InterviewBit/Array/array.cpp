#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

int maxSubArray(const vector<int> &A)
{
    int max_sum = A[0];
    int current_sum = A[0];

    // for (int i = 1; i < A.size(); i++)
    // {
    //     current_sum = max(A[i], current_sum + A[i]);
    //     max_sum = max(current_sum, max_sum);
    // }
    for (auto const i : A)
    {
        current_sum = max(i, current_sum + i);
        max_sum = max(current_sum, max_sum);
    }

    return max_sum;
}

int pow_ten(int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        res = res * 10;
    }
    return res;
}

// vector<int> plusOne(vector<int> &A)
// {
//     int num = 0;
//     for (int i = 0; i < A.size(); i++)
//     {
//         num += A[i] * pow_ten(A.size() - i - 1);
//     }
//     num += 1;
//     cout << num << endl;
//     vector<int> res;
//     do
//     {
//         res.insert(res.begin(), num % 10);
//         num /= 10;
//     } while (num != 0);
//     return res;
// }

vector<int> plusOne(vector<int> &A)
{
    int carry = 1; // Initialize carry to 1 since we want to add 1
    int n = A.size();

    // Ignore leading zeroes
    int leadingZeroes = 0;
    while (leadingZeroes < n && A[leadingZeroes] == 0)
    {
        leadingZeroes++;
    }

    // Add 1 starting from the least significant digit
    for (int i = n - 1; i >= leadingZeroes; i--)
    {
        int sum = A[i] + carry;
        A[i] = sum % 10;  // Update the current digit
        carry = sum / 10; // Update the carry for the next digit
    }

    // If there is still a carry, insert it at the beginning of the vector
    if (carry > 0)
        A.insert(A.begin(), carry);

    return A;
}

vector<int> Flip(string A)
{
    int n = A.size();
    int countZero = 0;
    int maxDiff = 0;
    int currDiff = 0;
    int start = 0;
    int end = 0;
    int ansStart = 0;
    int ansEnd = 0;
    bool allOnes = true;

    // Count the number of zeros and check if the string has all ones
    for (int i = 0; i < n; i++)
    {
        if (A[i] == '0')
        {
            countZero++;
            allOnes = false;
        }
    }

    // If all ones, return empty array
    if (allOnes)
        return std::vector<int>();

    for (int i = 0; i < n; i++)
    {
        // If the current element is 1, decrease the current difference by 1
        if (A[i] == '1')
        {
            currDiff--;
        }
        // If the current element is 0, increase the current difference by 1
        else
        {
            currDiff++;
        }

        // If the current difference is greater than the maximum difference so far,
        // update the maximum difference and the indices
        if (currDiff > maxDiff)
        {
            maxDiff = currDiff;
            ansStart = start;
            ansEnd = i;
        }
        // If the current difference becomes negative, reset the difference and update the start index
        if (currDiff < 0)
        {
            currDiff = 0;
            start = i + 1;
        }
    }

    std::vector<int> result;
    result.push_back(ansStart + 1); // Add 1 to the indices since the problem is 1-based indexing
    result.push_back(ansEnd + 1);

    return result;
}

//----------------------------------------------------------------

int countBits(int n)
{
    int numBits = 0;

    while (n > 0)
    {
        numBits++;
        n >>= 1; // Right shift the number by 1 bit
    }

    return numBits;
}

vector<int> flip(string A)
{
    int so = 0;
    int max = so;
    int L, R;
    for (int j = 0; j < 1; j++)
    {
        for (int i = j; i < A.size() - 1; i++)
        {
            if (A[i] == '0')
            {
                so++;
                if (max < so)
                {
                    R = i;
                    L = j;
                    max = so;
                    cout << so << " ";
                }
            }
        }
    }
    return {L + 1, R + 1};
}
int countSetBits(int n)
{
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        int num = i;
        while (num > 0)
        {
            count++;
            num &= (num - 1); // Clears the least significant set bit
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A = {97, 0, -461, -125, -404, -59, -322, -495, -288, -341, -449, -313, -192, -214, -389, -202, -183, -72, -416, -455, -187, -242, -416, 39, -198, -338, -465, -248, -25, -398, -97, -461, -214, -423, -407, -77, -190, -67, -178, -410, -160, 72, -350, -31, -85, -247, -319, -462, -303, -48, -354, -110, 17, 60, 19, 80, -218, -28, -426, -366, -140, 50};
    // cout << maxSubArray(A);

    vector<int> B = {0, 1, 2, 3};
    // for (auto const &i : plusOne(B))
    // {
    //     cout << i << " ";
    // }

    // string C = "10000";
    // for (auto const &i : flip(C))
    // {
    //     cout << i << " ";
    // }

    // for (auto const &i : binary(7))
    // {
    //     cout << i << " ";
    // }
    vector<int> C = {81, 13, 2, 7, 96};
    // cout << countBits(15);

    int x = 0;
    while ((1 << x) <= 16)
    {
        x++;
    }

    cout << x;

    return 0;
}
