#include <iostream>
#include <vector>
#include <algorithm>    //resever
#include <string>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};

int main(int argc, char **argv)
{
    string s = "hello world";
    reverse(s.begin(), s.end());   //algorithm库里面
    cout << s << endl;
    vector<char> vec{'h','e','l', 'l', 'o'};
    Solution *so = new Solution();
    so->reverseString(vec);
    for( auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}