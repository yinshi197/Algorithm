#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};
        vector<int> ret;

        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }
        
        int left = 0;
        int right = 0;
        for(int i = 0; i < s.size(); i++)
        {
            right = max(right, hash[s[i] - 'a']);
            if(right == i)
            {
                ret.push_back(right - left + 1);
                left = i + 1;
            }
        }

        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    Solution *so = new Solution();
    string s = "ababcbacadefegdehijhklij";
    vector<int> ret = so->partitionLabels(s);

    for(auto i : ret)   cout << i << " ";

    return 0;
}