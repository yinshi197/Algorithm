#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex)
    {   
        ret.push_back(path);
        if(startIndex >= nums.size()) return;

        for(int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);

        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution *so = new Solution();
    vector<vector<int>> ret = so->subsets(nums);
    for(auto vec : ret)
    {
        for(auto i : vec)
        {
            cout << i << " ";
        }

        cout << endl;
    }
    return 0;
}