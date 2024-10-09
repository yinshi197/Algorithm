#include <iostream>
#include <vector>
#include <string>

using namespace std;


//本题的重点是元素排列是有序的，取绝对值是两边往中间排序
//排序从大往小排序，比较左右节点的"绝对值"可以获取最大值。
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans = nums;
        int left = 0;
        int lenth = nums.size();
        int right = lenth - 1;
        for(int i = lenth - 1; i >= 0; i--)
        {
            int x = nums[left] * nums[left];
            int y = nums[right] * nums[right];

            if(x > y)
            {
                ans[i] = x;
                left++; //更新节点找下一个最大值
            }
            else
            {
                ans[i] = y;
                right--;
            }
        }
        return ans;
    }
};

int main(int argc, char **argv)
{
    bool ret;
    Solution *so = new Solution();
    vector<int> vec = {-4,-1,0,3,10};
    vec = so->sortedSquares(vec);
    for(auto i : vec)
    {
        cout << i << " ";
    }
    return 0;
}