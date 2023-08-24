#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {2, 4, 2, 5, 1};
    v.push_back(3); // [2, 4, 2, 5, 1, 3]
    v.push_back(2); // [2, 4, 2, 5, 1, 3, 2]
    v.push_back(5); // [2, 4, 2, 5, 1, 3, 2, 5]
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << v.back() << endl;
    cout << "Popped " << endl;
    v.pop_back();
    cout << v.back() << endl;
}