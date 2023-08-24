#include <bits/stdc++.h>
using namespace std;

int index_of_min_element_in_rotated_array(vector<int> const arr)
{
    int start = 0;
    int n = arr.size(), end = n - 1;
    if (n == 1)
        return 0;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] < arr[(mid + 1) % n] && arr[mid] < arr[(mid - 1 + n) % n])
            return mid;
        else if (arr[end] < arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int how_many_times_a_sorted_array_is_rotated(vector<int> &arr)
{
    return index_of_min_element_in_rotated_array(arr);
}

int find_element_in_rotated_array(vector<int> &arr, int num)
{
    int min_index = index_of_min_element_in_rotated_array(arr);
    if (arr[min_index] == num)
        return min_index;

    if (binary_search(arr.begin(), arr.begin() + min_index, num))
        return lower_bound(arr.begin(), arr.begin() + min_index, num) - arr.begin();

    else if (binary_search(arr.begin() + min_index + 1, arr.end(), num))
        return (lower_bound(arr.begin() + min_index + 1, arr.end(), num) - arr.begin());

    else
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    // cout << index_of_min_element_in_rotated_array(a) << endl;
    cout << find_element_in_rotated_array(a, 1) << endl;

    return 0;
}