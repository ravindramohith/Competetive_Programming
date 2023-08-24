#include <bits/stdc++.h>
using namespace std;

vector<int> nearest_large_number_to_left(vector<int> array)
{
    stack<pair<int, int>> stack;
    vector<int> result;
    for (int i = 0; i < array.size(); i++)
    {
        while (!stack.empty())
        {
            if (array[i] > stack.top().first)
                stack.pop();

            else
            {
                result.push_back(stack.top().second);
                break;
            }
        }
        if (stack.empty())
            result.push_back(-1);

        stack.push({array[i], i});
    }

    return result;
}

vector<int> stock_span(vector<int> array)
{
    vector<int> NGL = nearest_large_number_to_left(array);
    vector<int> res;
    for (int i = 0; i < NGL.size(); i++)
    {
        res.push_back(i - NGL[i]);
    }
    return res;
}

int main()
{
    vector<int> a = {31, 27, 14, 21, 30, 22}, b = {2, 1, 2, 4};
    for (auto i : stock_span(a))
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : stock_span(b))
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}