#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &arr, int num)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (num == arr[mid])
            return mid;

        else
        {
            if (num > arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int binary_search_reverse_sorted_array(vector<int> &arr, int num)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (num == arr[mid])
            return mid;

        else
        {
            if (num > arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }

    return -1;
}

int first_occurrence(vector<int> const &arr, int num)
{
    int start = 0;
    int end = arr.size() - 1;
    int res = -1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (num == arr[mid])
        {
            res = mid;
            end = mid - 1;
        }

        else
        {
            if (num > arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return res;
}

int last_occurence(vector<int> const &arr, int num)
{
    int start = 0;
    int end = arr.size() - 1;
    int res = -1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (num == arr[mid])
        {
            res = mid;
            start = mid + 1;
        }

        else
        {
            if (num > arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18};
    cout << binary_search(arr, 6) << endl;
    reverse(arr.begin(), arr.end());
    cout << binary_search_reverse_sorted_array(arr, 6) << endl;
    vector<int> arr_ = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 12, 13, 14, 15, 16, 18};
    cout << first_occurrence(arr_, 10) << endl;
    cout << last_occurence(arr_, 10) << endl;
    cout << "count of element: " << 10 << " is " << last_occurence(arr_, 10) - first_occurrence(arr_, 10) + 1 << endl;
    return 0;
}