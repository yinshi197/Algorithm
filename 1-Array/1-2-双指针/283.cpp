#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int showIndex = 0;
        for(auto i : nums)
        {
            if(i != 0)
            {
                nums[showIndex] = i;
                showIndex++;
            }
        }

        for(showIndex; showIndex <= nums.size() - 1; showIndex++)
        {
            nums[showIndex] = 0;
        }
    }
};

int main(int argc, char **argv)
{
    int ret;
    Solution *so = new Solution();
    vector<int> vec = {0,0,1,1,1,2,2,3,3,4};
    so->moveZeroes(vec);
    for(auto i : vec)
    {
        cout << i << " ";
    }
    return 0;
}
