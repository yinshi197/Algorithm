#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        list<vector<int>> ret;
        sort(people.begin(), people.end(), cmp);
        for(int i = 0; i < people.size(); i++)
        {
            int position = people[i][1];
            list<vector<int>>::iterator it = ret.begin();
            while(position--) it++;
            ret.insert(it, people[i]);
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};

int main()
{
    vector<vector<int>> people = { {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2} };

    Solution *so = new Solution();
    vector<vector<int>> ret = so->reconstructQueue(people);

    for(auto vec : ret)
    {
        cout << vec[0] << " " << vec[1] << endl;
    }

    return 0;
}