#include <iostream>

using namespace std;

class Solution {
public:
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
    string s = "anagram";
    string t = "nagaram";
    Solution *so = new Solution();
    bool ret = so->isAnagram(s, t);
    cout << ret << endl;
    return 0;
}