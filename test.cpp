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
    int maxSubArray(vector<int>& nums) {
        int ret = INT32_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum > ret)
            {
                ret = sum;
            }
            if(sum <= 0)
            {
                sum = 0;
            }
        }

        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> nums = {-2,-1,-3,-4,-1,-2,-1,-5,-4};
    Solution *so = new Solution();
    int ret = so->maxSubArray(nums);
    cout << ret << endl;

    return 0;
}