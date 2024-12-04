#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> ret;
    vector<string> path;

    bool isPalindrome(const string& s, int start, int end)
    {
        for(int i = start, j = end; i < j; i++, j--)
        {
            if(s[i] != s[j])    return false;
        }

        return true;
    }

    void backtracking(const string& s, int startIndex)
    {
        if(startIndex >= s.size())
        {
            ret.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); i++)
        {
            if(isPalindrome(s, startIndex, i))
            {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else continue;
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ret;
    }
};

int main(int argc, char **argv)
{   
    string s = "aab";
    Solution *so = new Solution();
    vector<vector<string>> ret = so->partition(s);
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