#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        
        ret.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] > ret.back()[1])
            {
                ret.push_back(intervals[i]);
            }
            else 
            {
                ret.back()[1] = max(intervals[i][1], ret.back()[1]);
            }
        }

        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution *so = new Solution();
    vector<vector<int>> intervals = { {1, 4}, {4, 5}};
    vector<vector<int>> ret = so->merge(intervals);

    for(const vector<int>& vec : ret) cout << vec[0] << " " << vec[1] << endl;

    return 0;
}