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
    int jump(vector<int>& nums) {
        int ret = 0;
        int curDistance = 0;
        int nextDistance = 0;
        for(int i = 0; i < nums.size() - 1; i++)    //一定是可以到达终点的
        {
            nextDistance = max(nextDistance, nums[i] + i);
            if(i == curDistance)
            {
                ret++;
                curDistance = nextDistance;
            }
        }

        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> nums = {2,3,0,1,4};
    Solution *so = new Solution();
    int ret = so->jump(nums);
    cout << ret << endl;

    return 0;
}