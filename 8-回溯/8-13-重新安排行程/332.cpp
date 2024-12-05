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
    //unordered_map<出发机场, map<到达机场, 航班次数>> targets;
    unordered_map<string, map<string, int>> targets;

    //只需要找到一个行程，就是在树形结构中唯一的一条通向叶子节点的路线
    bool backtracking(int tickNum, vector<string>& ret)
    {
        if(ret.size() == tickNum + 1)
        {
            return true;
        }

        //需要引用，否则target修改不会影响targets
        //加上引用之后，就必须在 string 前面加上 const，因为map中的key 是不可修改了，这就是语法规定
        //map<到达机场, 航班次数会按字母顺序从小到大被取出
        for(pair<const string, int>& target : targets[ret[ret.size() - 1]])
        {
            if(target.second > 0)   //存在航班
            {
                ret.push_back(target.first);
                target.second--;
                if(backtracking(tickNum, ret)) return true;
                ret.pop_back();
                target.second++;
            }
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ret;
        for(const vector<string>& vec : tickets)
        {
            targets[vec[0]][vec[1]]++;
        }
        ret.push_back("JFK");
        backtracking(tickets.size(), ret);
        
        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<vector<string>> tickets =  {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"}, {"ATL","SFO"}};
    Solution *so = new Solution();
    vector<string> ret = so->findItinerary(tickets);
    for(auto s : ret)
    {
        cout << s << " ";
    }

    return 0;
}