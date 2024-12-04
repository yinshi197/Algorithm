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

    void backtracking(vector<int>& nums, int startIndex)
    {   
        if(path.size() > 1)
        {
            ret.push_back(path);
            //不需要return因为要取树上所有的节点(子集问题)
        }

        unordered_set<int> uset;    //每层定义一个，只在本层生效
        for(int i = startIndex; i < nums.size(); i++)
        {
            if((!path.empty() && nums[i] < path.back())
                || uset.find(nums[i]) != uset.end())    //find()返回值：指向键等于 key 的元素的迭代器。若找不到这种元素，则返回尾后（见 end() ）迭代器。
                continue;
            else
            {
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);

        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> nums = {4,6,7,7};
    Solution *so = new Solution();
    vector<vector<int>> ret = so->findSubsequences(nums);
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