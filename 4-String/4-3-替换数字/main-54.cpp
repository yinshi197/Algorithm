#include <iostream>
#include <vector>
#include <algorithm>    //resever
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s) {
        int sOldIndex = s.size() - 1;   //未扩充前的下标
        int count = 0;
        for(auto i : s)
        {
            if(i >= '0' && i <= '9')
                count++;
        }

        //关键点：resize的使用
        s.resize(s.size() + count * 5);
        int newIndex = s.size() - 1;
        while(sOldIndex >= 0)   //0不能漏掉
        {
            if(s[sOldIndex] >= '0' && s[sOldIndex] <= '9')
            {
                //number
                s[newIndex--] = 'r';
                s[newIndex--] = 'e';
                s[newIndex--] = 'b';
                s[newIndex--] = 'm';
                s[newIndex--] = 'u';
                s[newIndex--] = 'n';
            }else
            {
                s[newIndex--] = s[sOldIndex];
            }
            sOldIndex--;
        }

        return s;
    }
};

int main(int argc, char **argv)
{
    string s;
    cin >> s;
    Solution *so = new Solution();
    s = so->reverseStr(s);
    cout << s << endl;
    return 0;
}