#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    const string letterMap[10] = {
        "",     //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz", //9
    };

    vector<string> ret;    //存放结果集合
    string s;   //存放结果

    void backtracking(const string& digits, int index)
    {
        if(index == digits.size())
        {
            ret.push_back(s);
            return;
        }

        int digit = digits[index] - '0';
        string letter = letterMap[digit];
        for(int i = 0; i < letter.size(); i++)
        {
            s.push_back(letter[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ret;
        backtracking(digits, 0);

        return ret;
    }
};

int main(int argc, char **argv)
{   
    string s;
    cin >> s;
    Solution *so = new Solution();
    vector<string> ret = so->letterCombinations(s);
    for(auto str : ret)
    {
        cout << str << " ";
    }
    
    return 0;
}