#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int lenth = 0;
        int sum = 0;
        int ret = INT32_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while(sum >= target)
            {
                lenth = (i - left + 1); 
                ret = ret > lenth ? lenth : ret;
                sum -= nums[left++];    //先sum -= nums[left]再进行left++,变更滑动窗口起始位置
            }
        }
        return  ret == INT32_MAX ? 0 : ret;   
    }
};

int main(int argc, char **argv)
{
    int ret;
    Solution *so = new Solution();
    vector<int> vec = {2,3,1,2,4,3};
    ret = so->minSubArrayLen(7, vec);
    cout << ret << endl;
    return 0;
}
