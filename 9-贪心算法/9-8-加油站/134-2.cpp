#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int curSum = 0;
        int totalSum = 0;

        for(int i = 0; i < gas.size(); i++)
        {
            int rest = gas[i] - cost[i];
            curSum += rest;
            totalSum += rest;

            if(curSum < 0)
            {
                start = i + 1;
                curSum = 0;
            }
        }

        if(totalSum < 0) return -1;

        return start;
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