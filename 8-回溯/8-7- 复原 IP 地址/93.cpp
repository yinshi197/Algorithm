#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ret;

    bool isValid(const string& s, int start, int end)
    {
        if(start > end) return false;
        if(s[start] == '0' && start != end) return false;   //0xx
        int num = 0;
        for(int i = start; i <= end; i++)
        {
            if(s[i] > '9' || s[i] < '0')    return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }

        return true;
    }

    //变量pointNum，记录添加逗点的数量。
    void backtracking(string& s, int startIndex, int pointNum)
    {   
        if(pointNum == 3)
        {
            if(isValid(s, startIndex, s.size() - 1))
            {
                ret.push_back(s);
            }   
            
            return;
        }

        for(int i = startIndex; i < s.size(); i++)
        {
            if(isValid(s, startIndex, i))
            {
                s.insert(s.begin() + i + 1, '.');   //插入一个.
                backtracking(s, i + 2, pointNum + 1);
                s.erase(s.begin() + i + 1);
            }
            else break; //出现不合法，直接返回。
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);

        return ret;
    }
};

int main(int argc, char **argv)
{   
    string s = "101023";
    Solution *so = new Solution();
    vector<string> ret = so->restoreIpAddresses(s);
    for(auto s : ret)
    {
        cout << s << endl;
    }
    return 0;
}