#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        s = handle(s);
        t = handle(t);
        return s == t;
    }

    string handle(string s)
    {
        int showIndex = 0;
        for(auto ch : s)
        {
            if(ch != '#')
            {
                s[showIndex] = ch;
                showIndex++;
            }
            else if(showIndex > 0)  //防止越界 "#ab#"
            {
                showIndex--;
                s[showIndex] = ' ';
            }
        }

        s = s.substr(0, showIndex);
        return s;
    }
};

int main(int argc, char **argv)
{
    bool ret;
    Solution *so = new Solution();
    string s = "ab##";
    string t = "c#d#";
    ret = so->backspaceCompare(s, t);
    cout << "ret = " << ret << endl;
    return 0;
}
