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
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for(int i = 0; i < prices.size() - 1; i++)
        {
            ret += max(prices[i + 1] - prices[i], 0);
        }

        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> nums = {7, 1, 5, 10, 3, 6, 4};
    Solution *so = new Solution();
    int ret = so->maxProfit(nums);
    cout << ret << endl;

    return 0;
}