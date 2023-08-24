#include <bits/stdc++.h>
#include <vector>
using namespace std;

// { 3, 4, 6, 8, 12, 13, 14, 17 }
//   ↑ s.begin()              ↑ s.end()

int main()
{
    vector<int> v = {2, 4, 2, 5, 1};
    sort(v.begin(), v.end());
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    reverse(v.begin(), v.end());
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    random_shuffle(v.begin(), v.end());
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}