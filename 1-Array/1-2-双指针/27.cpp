#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for(int i : nums)
        {
            if(i != val)
            {
                nums[slowIndex] = i;
                slowIndex++;
            }
        }

        return slowIndex;
    }
};

int main(int argc, char **argv)
{
    bool ret;
    Solution *so = new Solution();
    vector<int> vec = {0,1,2,2,3,0,4,2};
    so->removeElement(vec, 2);
    cout << ret << endl;
    for(auto i : vec)
    {
        cout << i << " ";
    }
    return 0;
}
