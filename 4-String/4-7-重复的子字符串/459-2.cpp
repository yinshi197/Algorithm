#include <iostream>
#include <vector>
#include <algorithm>    //resever
#include <string>

using namespace std;

class Solution {
public:
    void getNext(int *next, const string& s)
    {
        //1.初始化
        int j = -1;     //j指向前缀末尾位置，i指向后缀末尾位置。
        next[0] = j;    //前缀表统一减一的记录方法

        
        for(int i = 1; i < s.size(); i++)
        {   
            //2.处理前后缀不同的前况
            while(j >= 0 && s[i] != s[j + 1])
                j = next[j];    //向前回退

            //3.处理前后缀相同的情况
            if(s[i] == s[j + 1])
            {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        
        if(s.size() == 0) return false;

        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if(next[len - 1] != -1 && len % (len - next[len - 1] -1) == 0)
        {
            return true;
        }

        return false;
    }
};

int main(int argc, char **argv)
{
    string s = "abcabcabcabc";
    vector<int> next(s.size());
    Solution *so = new Solution();
    bool ret = so->repeatedSubstringPattern(s);
    cout << ret << "\n";

    return 0;
}