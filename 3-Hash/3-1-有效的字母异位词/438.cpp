#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        set<char> hash;
        for(int i = 0; i < p.size(); i++) hash.insert(p[i]);
        int gap = p.size();
        if(gap < 0 || gap > s.size()) return {};

        vector<int> ans;
        for(int i = 0; i <= s.size() - gap; i++)
        {
            if(hash.count(s[i]))
            {
                string temp = s.substr(i, gap);
                if(isAnagram(temp,p))
                {
                    ans.push_back(i);
                }
            }     
        }

        return ans;
    }

    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int record[26]{0,};
        for(int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a']++;
        }

        for(int i = 0; i < t.size(); i++)
        {
            record[t[i] - 'a']--;
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(record[s[i] - 'a']) return false;
        }

        return true;
    }
};

int main(int argc, char **argv)
{
    string s = "abab";
    string p = "ab";
    Solution *so = new Solution();
    vector<int> ans = so->findAnagrams(s, p);
    for(auto i : ans)
    {
        cout << i << " ";
        cout << endl;
    }
    return 0;
}

//虽然通过了但是太慢了，还可以优化