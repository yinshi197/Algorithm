#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    void getCommed(string& s)
    {
        if(s == "push") 
        {
            int val;
            cin >> val;
            push(val);
        }

        if(s == "hmy")
        {
            hmy();
        }

        if(s == "hmx")
        {
            int val;
            cin >> val;
            hmx(val);
        }

        if(s == "erase")
        {
            int val;
            cin >> val;
            erase(val);
        }

        if(s == "clr")
        {
            clr();
        }
    }

    void push(int val)
    {
        map_[val]++;
    }

    void hmy()
    {
        cout << map_.size() << endl;
    }

    void hmx(int val)
    {
        if(map_.find(val) != map_.end()) 
        {
            cout << map_[val] << endl;
        }
        else cout << 0 << endl;
    }

    void erase(int val)
    {
        if(map_.find(val) != map_.end()) 
        {
            if(map_[val] > 1)   map_[val]--;
            else map_.erase(val);
        }   
    }

    void clr()
    {
        map_.clear();
    }

    unordered_map<int, int> map_;
};

int main()
{
    Solution *so = new Solution();
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        so->getCommed(s);
    }

    return 0;
}