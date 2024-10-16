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

    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = -1;
        for(int i = 0; i < haystack.size(); i++)
        {
            while(j >= 0 && haystack[i] != needle[j + 1])
            {
                j = next[j];
            }

            if(haystack[i] == needle[j + 1])  j++;  //i++在for循环里面

            if(j == needle.size() - 1)
            {
                return (i - needle.size() + 1);
            }
        }

        return -1;
    }
};

int main(int argc, char **argv)
{
    string s = "babba";
    string t = "bbb";
    Solution *so = new Solution();
    int ret = so->strStr(s, t);
    cout << ret << endl;

    return 0;
}