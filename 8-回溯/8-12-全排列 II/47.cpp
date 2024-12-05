#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {   
            //树层上去重(used[i - 1] == false),因为回溯了使用后重新赋值为false
            //树枝上去重（used[i - 1] == true）
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;

            if(used[i] == false) 
            {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }

        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> nums = {1,2,3};
    Solution *so = new Solution();
    vector<vector<int>> ret = so->permuteUnique(nums);
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