#include <bits/stdc++.h>
using namespace std;

// int solution(vector<string> &S, int K)
// {
//     vector<int> values(26, 0);
//     for (char i = 'a'; i <= 'z'; i++)
//     {
//         for (int j = 0; j < S.size(); j++)
//         {
//             if (i == 'a')
//             {
//                 sort(S[j].begin(), S[j].end());
//             }
//             if (binary_search(S[j].begin(), S[j].end(), i))
//             {
//                 values[i - 'a']++;
//             }
//         }
//     }

//     for (auto i : values)
//     {
//         cout << i << " ";
//     }
// }

#include <vector>
#include <string>
#include <algorithm>

int solution(std::vector<std::string> &S, int K)
{
    int maxStrings = 0;
    int alphabetSize = 26; // Assuming only lowercase English letters (a-z)

    // Iterate through all possible bitmasks with exactly K bits set to 1
    for (int bitmask = 0; bitmask < (1 << alphabetSize); ++bitmask)
    {
        if (__builtin_popcount(bitmask) == K)
        {
            int count = 0;

            // Check how many strings can be built using the current bitmask
            for (const std::string &str : S)
            {
                bool possible = true;
                for (char c : str)
                {
                    if (!(bitmask & (1 << (c - 'a'))))
                    {
                        possible = false;
                        break;
                    }
                }
                if (possible)
                    ++count;
            }

            maxStrings = std::max(maxStrings, count);
        }
    }

    return maxStrings;
}

int sols(vector<int> &A)
{
    int curr = 0, i = 0, sum = 0;
    while (i < A.size())
    {
        A[i] += curr;
        curr = A[i] / 2;
        A[i] %= 2;
        sum += A[i];
        i++;
    }

    while (curr > 0)
    {
        sum += curr % 2;
        curr /= 2;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a = "abdc";
    sort(a.begin(), a.end());
    ;
    // cout << binary_search(a.begin(), a.end(), 'e');
    // cout << 'a'-97 << endl;
    // vector<string> test = {"abc", "abb", "cb", "a", "bbb"};
    // cout << solution(test, 2);

    vector<int> B = {1, 0, 4, 1, 19999999};
    cout << endl
         << sols(B);

    return 0;
}