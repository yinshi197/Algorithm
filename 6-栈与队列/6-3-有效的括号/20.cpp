#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        stack<char> st;
        for(auto ch : s)
        {
            if(ch == '(') st.push(')');
            else if(ch == '[') st.push(']');
            else if(ch == '{') st.push('}');
            else if(st.empty() || st.top() != ch) return false;
            else st.pop();
        }

        return st.empty();    
    }
};

int main(int argc, char **argv)
{
    string s = "({{[}})";
    Solution *so = new Solution();
    bool ret = so->isValid(s);
    cout << "ret = " << ret << endl;
}