#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getValue(string s, int k) {
        long long ret = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            int count0 = 0;
            int count1 = 0;
            //只有一个字符的子串
            if(s[i] == '0') count0++;
            else count1++;
            ret++;

            int length = 1;
            while(i + length < s.size())
            {
                if(s[i + length] == '0') count0++;
                else count1++;

                if(count0 > k && count1 > k)
                {
                    count0 = 0;
                    count1 = 0;
                    break;
                }
                else ret++;

                length++;
            }
        }

        return ret;
    }

    vector<vector<long long>> gettable(string s, int k) {
        long long ret = 0;
        vector<vector<long long>> table(s.size());
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 1; i + j <= s.size(); j++)
            {
                table[i].push_back(getValue(s.substr(i, j), k));
            }
        }

        for(auto vec : table)
        {
            for(auto i : vec)
            {
                cout << i << " ";
            }
            cout << endl;
        }

        return table;
    }

    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        vector<vector<long long>> table = gettable(s, k);
        vector<long long> ret;
        for(auto vec : queries)
        {
            int l = vec[0];
            int length = vec[1] - vec[0];
            if(length > table[l].size() - 1)
            {
                ret.push_back(table[l].back());
            }
            else ret.push_back(table[l][length]);
        }
        
        return ret;
    }
};

int main(int argc, char **argv)
{
    string s = "010101";
    vector<vector<int>> vect = {{0,5}, {1,4}, {2,3}};
    vector<long long> ret;
    Solution *so = new Solution();
    ret = so->countKConstraintSubstrings(s, 1, vect);
    for(auto i : ret)
    {
        cout << i << " ";
    }
    return 0;
}