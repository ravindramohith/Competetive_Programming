#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;
    cout << m["banana"] << "\n";
    map<string, int> s;
    cout << s["aybabtu"] << "\n"; // 0

    if (m.count("aybabtu"))
    {
        // key exists
    }
}