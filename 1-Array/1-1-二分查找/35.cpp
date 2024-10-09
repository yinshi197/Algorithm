#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;    //左闭右闭合
    
        while(left <= right)    //包含等于
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

        return left;

    }
};

int main(int argc, char **argv)
{
    Solution *so = new Solution();
    vector<int> vec = {-1,0,3,5,9,12};
    int ret = so->search(vec, 9);
    cout << ret << endl;
    return 0;
}
