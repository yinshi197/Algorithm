#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int mid = searchmid(nums, target);
        if(mid == -1)
        {
            return { -1, -1};
        }
        else
        {
            if(nums.size() == 1)
            {
                return { 0, 0};
            }

            if(mid == nums.size() - 1 || nums[mid] != nums[mid + 1])  //右节点
            {
                int right = mid;
                while(mid > 0 && nums[mid - 1] == target)
                {
                    mid--;
                }
                return {mid, right};
            }
            else if(mid == 0 || nums[mid] != nums[mid - 1])     //左节点
            {
                int left = mid;
                while(mid < nums.size() - 1 && nums[mid + 1] == target)
                {
                    mid++;
                }
                return {left, mid};
            }
            else //中间节点 
            {
                int left = mid, right = mid;
                while(left > 0 && nums[left - 1] == target)
                {
                    left--;
                }
                while(right < nums.size() - 1 && nums[right + 1] == target)
                {
                    right++;
                }

                return {left, right};
            }

        }
        
        return { -1, -1};
    }

    int searchmid(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() -1;

        while(left <= right)
        {
            int mid = (left + right) / 2;

            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else return mid;
        }

        return -1;
    }
};

int main(int argc, char **argv)
{
    int ret = -1;
    Solution *so = new Solution();
    vector<int> vec = {2, 2, 2};
    vector<int> ret2 = so->searchRange(vec, 2);
    cout << "[" << ret2[0] << "," << ret2[1] << "]" << endl;
    return 0;
}
