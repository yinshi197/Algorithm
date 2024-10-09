#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int showIndex = 0;
        for(auto i : nums)
        {
            if(i > nums[showIndex])
            {
                showIndex++;
                nums[showIndex] = i;
            }
        }

        return showIndex + 1;
    }
};

int main(int argc, char **argv)
{
    int ret;
    Solution *so = new Solution();
    vector<int> vec = {0,0,1,1,1,2,2,3,3,4};
    ret = so->removeDuplicates(vec);
    cout << ret << endl;
    for(auto i : vec)
    {
        cout << i << " ";
    }
    return 0;
}
