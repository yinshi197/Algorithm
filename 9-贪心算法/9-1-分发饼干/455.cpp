#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        int ret = 0;
        for(int i = g.size() - 1; i >= 0; i--)
        {
            if(index >= 0 && s[index] >= g[i])
            {
                ret++;
                index--;
            }
        }

        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> g = { 1, 2, 3 };
    vector<int> s = { 1, 1, 1 };
    Solution *so = new Solution();
    int ret = so->findContentChildren(g, s);
    cout << ret << endl;

    return 0;
}