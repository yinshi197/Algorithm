#include <iostream>
#include <vector>
#include <algorithm>    //resever
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        //1.清除空格
        clearSpace(s);
        //2.字符串翻转
        reverseString(s, 0, s.size() - 1);
        //3.翻转字符串
        int start = 0;
        for(int i = 0; i <= s.size(); i++)
        {
            if(s[i] == ' ' || i == s.size())
            {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }

        return s;
    }

    //左闭右闭
    void reverseString(string &s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    void clearSpace(string &s)
    {
        int slow = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
            {
                if(slow != 0)   s[slow++] = ' ';    //在单词前面手动添加空格，除了第一个单词
                while(i < s.size() && s[i] != ' ')
                {
                    s[slow++] = s[i++];
                }
            }
        }

        s.resize(slow);
    }
};

int main(int argc, char **argv)
{
    string s = "the sky is blue";
    Solution *so = new Solution();
    s = so->reverseWords(s);
    cout << s << endl;

    return 0;
}