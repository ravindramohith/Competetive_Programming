#include <bits/stdc++.h>
#include <set>
using namespace std;
int main()
{
    set<int> s = {2, 5, 6, 8, 5};
    cout << s.size() << "\n"; // 4
    for (auto x : s)
    {
        cout << x << "\t";
    }
    cout << s.count(5) << "\n"; // checks wheter 5 is there or not
    // s.erase(5); // all instances of 5 erased
    s.erase(s.find(5)); // all instances of 5 erased
    for (auto x : s)
    {
        cout << x << "\t";
    }
    cout << endl;
}