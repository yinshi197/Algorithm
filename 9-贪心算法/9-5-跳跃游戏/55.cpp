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
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size() == 1) return true;
        for(int i = 0; i <= cover; i++)
        {
            cover = max(i + nums[i], cover);
            if(cover >= nums.size() - 1) return true;
        }

        return false;
    }
};

int main(int argc, char **argv)
{   
    vector<int> nums = {0,2,3};
    Solution *so = new Solution();
    bool ret = so->canJump(nums);
    cout << ret << endl;

    return 0;
}