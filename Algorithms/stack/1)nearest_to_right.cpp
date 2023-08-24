#include <bits/stdc++.h>
using namespace std;

vector<int> nearest_large_number(vector<int> array)
{
    stack<int> stack;
    vector<int> result;
    for (int i = array.size() - 1; i >= 0; i--)
    {
        while (!stack.empty())
        {
            if (array[i] >= stack.top())
                stack.pop();

            else
            {
                result.push_back(stack.top());
                break;
            }
        }
        if (stack.empty())
            result.push_back(-1);

        stack.push(array[i]);
    }

    reverse(result.begin(), result.end());
    return result;
}

vector<int> nearest_small_number(vector<int> array)
{
    stack<int> stack;
    vector<int> result;
    for (int i = array.size() - 1; i >= 0; i--)
    {
        while (!stack.empty())
        {
            if (array[i] <= stack.top())
                stack.pop();

            else
            {
                result.push_back(stack.top());
                break;
            }
        }
        if (stack.empty())
            result.push_back(-1);

        stack.push(array[i]);
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {17, 18, 5, 4, 6, 1};
    for (auto i : nearest_large_number(a))
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> b = {4, 5, 2, 10, 8};
    for (auto i : nearest_small_number(b))
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}