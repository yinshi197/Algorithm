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

        for(int i = startIndex; i < candidates.size() && curSum + candidates[i] <= target; i++)
        {
            if(i > startIndex && candidates[i] == candidates[i - 1])    continue;
            path.push_back(candidates[i]);
            backtracking(candidates, target, curSum + candidates[i], i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);

        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> vec = {10,1,2,7,6,1,5};
    Solution *so = new Solution();
    vector<vector<int>> ret = so->combinationSum2(vec, 8);
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