#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        int count = 1;  //非交叉数量
        sort(intervals.begin(), intervals.end(), cmp);

        int minright = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] >= minright)
            {
                count++;
                minright = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};

int main()
{
    vector<vector<int>> intervals = { {1, 2}, {2, 3}, {3, 4}, {1, 3} };

    Solution *so = new Solution();
    int ret = so->eraseOverlapIntervals(intervals);

    cout << ret << endl;

    return 0;
}