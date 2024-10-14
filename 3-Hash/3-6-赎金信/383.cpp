#include <iostream>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26]{0,};
        if(ransomNote.size() > magazine.size()) return false;

        for(int i = 0; i < ransomNote.size(); i++)
        {
            record[ransomNote[i] - 'a']++;
        }

        for(int i = 0; i < magazine.size(); i++)
        {
            record[magazine[i] - 'a']--;
        }

        for(int i = 0; i < ransomNote.size(); i++)
        {
            // > 0 表示还需要该元素
            if(record[ransomNote[i] - 'a'] > 0) return false;
        }

        return true;
    }
};

int main(int argc, char **argv)
{
    string s = "aa";
    string t = "aab";
    Solution *so = new Solution();
    bool ret = so->canConstruct(s, t);
    cout << ret << endl;
    return 0;
}