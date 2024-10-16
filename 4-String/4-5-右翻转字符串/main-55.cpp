#include <iostream>
#include <vector>
#include <algorithm>    //resever
#include <string>

using namespace std;

class Solution {
public:
    string rightReverseStr(string s, int k) {
        reverseString(s, 0, s.size() - 1);
        reverseString(s, 0, k - 1);
        reverseString(s, k, s.size() - 1);
        
        return s;
    }

    //左闭右闭
    void reverseString(string &s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};

int main(int argc, char **argv)
{
    int k;
    string s;
    cin >> k >> s; 
    Solution *so = new Solution();
    s = so->rightReverseStr(s, k);
    cout << s << endl;

    return 0;
}