#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); //默认从小到大排序,greater<int>()从大到小排序
        //a + b + c + d =  target;
        //nums[i] + nums[j] + nums[left] + nums[right] == target
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            //一层剪枝
            if(nums[i] > target && nums[i] >= 0)    break;

            // [-1, -1, 2] 使用前去重会错过
            //去重a,连续两个元素相等,跳过后一个. (a + b + c = 0)
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < nums.size(); j++)
            {
                //二层剪枝
                if(nums[i] + nums[j] > target && nums[i] >= 0) break;

                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = nums.size() - 1;
                while(right > left)
                {
                    //long long sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if((long) nums[j] + nums[i] + nums[left] + nums[right] > target) right--;
                    else if((long) nums[j] + nums[i] + nums[left] + nums[right] < target) left++;
                    else
                    {
                        ans.push_back(vector<int>{nums[i], nums[j] ,nums[left], nums[right]});
                        while(right > left && nums[right] == nums[right - 1]) right--;
                        while(right > left && nums[left] == nums[left + 1]) left++;

                        //找到答案,双指针同时收缩,因为i在这层循环是不变的 left + right 解是唯一的,不能单独移动
                        left++;
                        right--;
                    }
                }
            }
            
        }

        return ans;
    }
};

int main(int argc, char **argv)
{
    vector<int> vec{2,2,2,2,2};
    Solution *so = new Solution();
    vector<vector<int>> ret = so->fourSum(vec, 8);
    for(auto i : ret)
    {
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}