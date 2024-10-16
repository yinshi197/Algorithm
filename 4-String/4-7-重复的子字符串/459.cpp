#include <iostream>
#include <vector>
#include <algorithm>    //resever
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //如果有循环节,2S必有S子串数量大于2,比如s = "aabaab"
        //2s = "aabaabaabaabaab"
        //从下标1开始找，必不可能在size()找到s(2s中第二个s的起点).
        return (s + s).find(s, 1) != s.size();
    }
};

int main(int argc, char **argv)
{
    string s = "abcabcabcabc";
    Solution *so = new Solution();
    bool ret = so->repeatedSubstringPattern(s);
    cout << ret <<"\n";
    return 0;
}