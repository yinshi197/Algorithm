#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        st.push('/');
        path.push_back('/');

        for(int i = 0; i < path.size(); i++)
        {
            if(i < path.size() - 2 && path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '/' && i > 0 && st.top() == '/')
            {
                if(st.size() != 1) st.pop();
                while(!st.empty() && st.top() != '/')
                {
                    st.pop();
                }
                i += 2;
            }
            else if(i < path.size() - 1 && path[i] == '.' && path[i + 1] == '/' && i > 0 && st.top() == '/')
            {
                i += 1;
            }
            else
            {
                if(path[i] == '/' && st.top() == '/') continue;
                st.push(path[i]);
            }
        }
        
        string ret;
        while(!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }

        reverse(ret.begin(), ret.end());
        if(ret.size() > 1 && ret.back() == '/')   ret.resize(ret.size() - 1);
        return ret;
    }
};

int main(int argc, char **argv)
{
    string path = "/a//b////c/d//././/..";
    Solution *so = new Solution();
    string ret = so->simplifyPath(path);
    cout << ret << endl;
    return 0;
}