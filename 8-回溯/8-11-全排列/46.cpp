
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
            if(used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> nums = {1,2,3};
    Solution *so = new Solution();
    vector<vector<int>> ret = so->permute(nums);
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