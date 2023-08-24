#include <bits/stdc++.h>
using namespace std;

vector<int> nearest_small_number_to_left(vector<int> array)
{
    stack<pair<int, int>> stack;
    vector<int> result;
    for (int i = 0; i < array.size(); i++)
    {
        while (!stack.empty())
        {
            if (array[i] < stack.top().first)
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

vector<int> nearest_small_number_to_right(vector<int> array)
{
    int n = array.size();
    stack<pair<int, int>> stack;
    vector<int> result;
    for (int i = array.size() - 1; i >= 0; i--)
    {
        while (!stack.empty())
        {
            if (array[i] < stack.top().first)
                stack.pop();

            else
            {
                result.push_back(stack.top().second);
                break;
            }
        }
        if (stack.empty())
            result.push_back(n);

        stack.push({array[i], i});
    }

    reverse(result.begin(), result.end());
    return result;
}

int MAH(vector<int> array)
{
    vector<int> NGL = nearest_small_number_to_left(array);
    vector<int> NGR = nearest_small_number_to_right(array);
    vector<int> res;
    for (int i = 0; i < NGL.size(); i++)
    {
        res.push_back((NGR[i] - NGL[i] - 1) * array[i]);
    }
    return *max_element(res.begin(), res.end());
}

int main()
{
    vector<int> a = {6, 2, 5, 4, 5, 1, 6}, b = {2, 1, 2, 4};
    cout << MAH(a) << endl;
    cout << MAH(b) << endl;


    return 0;
}