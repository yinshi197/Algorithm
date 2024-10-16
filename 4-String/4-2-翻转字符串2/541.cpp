#include <iostream>
#include <vector>
#include <algorithm>    //resever
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += (2 * k))
        {
            if(i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {   //剩下情况需要翻转的字符串少于k，直接翻转剩下的字符串
                //剩下的情况都需要执行下面的语句，而且for()会自动i += (2 * k)，退出
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main(int argc, char **argv)
{
    string s = "abcdefg";
    Solution *so = new Solution();
    s = so->reverseStr(s, 2);
    cout << s << endl;
    return 0;
}