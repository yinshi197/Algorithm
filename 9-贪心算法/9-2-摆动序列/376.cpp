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
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int curdiff = 0;
        int prediff = 0;
        int ret = 1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            curdiff = nums[i + 1] - nums[i];
            if((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0))
            {
                ret++;
                prediff = curdiff;
            }
        }

        return ret;
    }
};

int main(int argc, char **argv)
{   
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    Solution *so = new Solution();
    int ret = so->wiggleMaxLength(nums);
    cout << ret << endl;

    return 0;
}