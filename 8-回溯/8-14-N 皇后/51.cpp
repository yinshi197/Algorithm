#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> ret;
    vector<string> path;

    bool isVaild(int row, int col, vector<string>& chessborad, int n)
    {
        //检查列
        for(int i = 0; i < row; i++)
        {
            if(chessborad[i][col] == 'Q') return false;
        }

        //检查45度
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if(chessborad[i][j] == 'Q') return false;
        }

        //检查135度
        for(int i = row - 1, j = col + 1; i >= 0 && j <= n; i--, j++)
        {
            if(chessborad[i][j] == 'Q') return false;
        }

        return true;
    }

    void backtracking(int n, int row, vector<string>& chessborad)
    {
        if(row == n)
        {
            ret.push_back(chessborad);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(isVaild(row, col, chessborad, n))
            {
                chessborad[row][col] = 'Q';
                backtracking(n, row + 1, chessborad);
                chessborad[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessbroad(n, string(n, '.'));
        backtracking(n, 0, chessbroad);

        return ret;
    }
};

int main(int argc, char **argv)
{   
    Solution *so = new Solution();
    vector<vector<string>> ret = so->solveNQueens(10);
    for(auto vec : ret)
    {
        for(auto s : vec)
        {
            cout << s << endl;
        }
        cout << "<<======>>" << endl;
    }

    return 0;
}