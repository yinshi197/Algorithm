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
    bool isVaild(int row, int col, char val, vector<vector<char>>& borad)
    {
        for(int i = 0; i < 9; i++)  //判断是否行重复
        {
            if(borad[row][i] == val) return false;
        }

        for(int j = 0; j < 9; j++)  //判断列重复
        {
            if(borad[j][col] == val) return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int i = startRow; i < startRow + 3; i++)
        {
            for(int j = startCol; j < startCol + 3; j++)
            {
                if(borad[i][j] == val) return false;
            }
        }

        return true;
    }

    bool backtracking(vector<vector<char>>& borad)
    {
        for(int i = 0; i < borad.size(); i++)
        {
            for(int j = 0; j < borad[0].size(); j++)
            {
                if(borad[i][j] != '.') continue;
                for(char k = '1'; k <= '9'; k++)
                {
                    if(isVaild(i, j, k, borad))
                    {
                        borad[i][j] = k;
                        if(backtracking(borad)) return true;
                        borad[i][j] = '.';
                    }
                }
                return false;   //9个数都试完了，都不行返回false
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

int main(int argc, char **argv)
{   
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};
    Solution *so = new Solution();
    so->solveSudoku(board);
    for(auto vec : board)
    {
        for(auto s : vec)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}