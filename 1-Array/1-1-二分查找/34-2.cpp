#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() -1 ;

        if(right == -1)
        {
            return { -1, -1};
        }

        int mid = searchmid(nums, target, left, right);
        if(mid == -1)
        {
            return { -1, -1};
        }
        
        if(nums.size() == 1)
        {
            return { mid, mid};
        }

        //扩大找左分界
        while(mid > 0 && nums[mid - 1] == target)
        {
            mid = searchmid(nums, target, 0, mid - 1);
        }

        left = mid;

        while(mid < right && nums[mid + 1] == target)
        {
            mid = searchmid(nums, target, mid + 1, right);
        }

        right = mid;

        return { left, right};
    }

    int searchmid(vector<int>& nums, int target, int left, int right) 
    {
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
    vector<int> vec = {2, 2};
    vector<int> ret2 = so->searchRange(vec, 2);
    cout << "[" << ret2[0] << "," << ret2[1] << "]" << endl;
    return 0;
}
