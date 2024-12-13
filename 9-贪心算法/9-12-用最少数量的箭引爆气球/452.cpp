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
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int ret = 1;
        sort(points.begin(), points.end(), cmp);

        for(int i = 1; i < points.size(); i++)
        {
            if(points[i][0] > points[i - 1][1])
            {
                ret++;
            }
            else 
            {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }

        return ret;
    }
};

int main()
{
    vector<vector<int>> points = { {9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};

    Solution *so = new Solution();
    int ret = so->findMinArrowShots(points);

    cout << ret << endl;

    return 0;
}