#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinMax(vector<int> &A, int start, int end)
{
    if (start == end)
        return make_pair(A[start], A[end]);

    int mid = (end - start) / 2 + start;

    pair<int, int> maxmin1 = findMinMax(A, start, mid);
    pair<int, int> maxmin2 = findMinMax(A, mid + 1, end);

    int minNum = maxmin1.first < maxmin2.first ? maxmin1.first : maxmin2.first;
    int maxNum = maxmin1.second > maxmin2.second ? maxmin1.second : maxmin2.second;

    return make_pair(minNum, maxNum);
}

int solve(vector<int> &A)
{
    pair<int, int> maxMin = findMinMax(A, 0, A.size() - 1);
    cout << maxMin.first << " " << maxMin.second << endl;
    return maxMin.first + maxMin.second;
}

int main()
{

    vector<int> C = {97, 0, -461, -125, -404, -59, -322, -495, -288, -341, -449, -313, -192, -214, -389, -202, -183, -72, -416, -455, -187, -242, -416, 39, -198, -338, -465, -248, -25, -398, -97, -461, -214, -423, -407, -77, -190, -67, -178, -410, -160, 72, -350, -31, -85, -247, -319, -462, -303, -48, -354, -110, 17, 60, 19, 80, -218, -28, -426, -366, -140, 50};

    cout << solve(C) << endl;

    return 0;
}