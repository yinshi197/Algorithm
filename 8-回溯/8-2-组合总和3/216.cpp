#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;    //存放结果集合
    vector<int> path;   //存放结果

    void backtracking(int k, int retSum, int curSum, int startIndex)
    {
        if(path.size() == k)
        {
            if(retSum == curSum)    ret.push_back(path);
            return;
        }

        for(int i = startIndex; i <= 9 - (k - path.size()) + 1 && curSum + i <= retSum; i++)
        {
            path.push_back(i);
            backtracking(k, retSum, curSum + i, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return ret;
    }
};

int main(int argc, char **argv)
{   
    int n, k;
    cin >> k >> n;
    Solution *so = new Solution();
    vector<vector<int>> ret = so->combinationSum3(k, n);
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