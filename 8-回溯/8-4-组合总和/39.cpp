#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(vector<int>& candidates, int target, int curSum, int startIndex)
    {
        if(curSum == target)
        {
            ret.push_back(path);
            return;
        }

        //在处理 {8, 7, 4, 3} 和目标值 11 时，如果 curSum 已经较大，candidates[i] 较小，可能会导致 curSum + candidates[i] 刚好等于 target 的情况被跳过。
        for(int i = startIndex; i < candidates.size() && curSum + candidates[i] <= target; i++)
        {
            path.push_back(candidates[i]);
            backtracking(candidates, target, curSum + candidates[i], i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> vec = {8, 7, 4, 3};
    Solution *so = new Solution();
    vector<vector<int>> ret = so->combinationSum(vec, 11);
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