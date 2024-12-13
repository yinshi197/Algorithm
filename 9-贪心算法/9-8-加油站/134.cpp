#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int min = INT_MAX;
        for(int i = 0; i < gas.size(); i++)
        {
            int rest = gas[i] - cost[i];
            curSum += rest;
            if(curSum < min)
            {
                min = curSum;
            }
        }

        if(curSum < 0) return -1;
        if(min >= 0) return 0;  //从0站开始min都大于0

        for(int i = gas.size() - 1; i >= 0; i--)
        {
            int rest = gas[i] - cost[i];
            min += rest;
            if(min >= 0) return i;
        }

        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    Solution *so = new Solution();
    int ret = so->canCompleteCircuit(gas, cost);

    cout << ret << endl;

    return 0;
}