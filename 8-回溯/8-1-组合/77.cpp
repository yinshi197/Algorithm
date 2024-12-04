#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ret;    //存放结果集合
    vector<int> path;   //存放结果

    void backtracking(int n, int k, int startIndex)
    {
        if(path.size() == k)
        {
            ret.push_back(path);
            return;
        }

        //剩下的元素个数要够凑够k个
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back(); //回溯
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ret;
    }
};

int main(int argc, char **argv)
{   
    int n, k;
    cin >> n >> k;
    Solution *so = new Solution();
    vector<vector<int>> ret = so->combine(n, k);
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