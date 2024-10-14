#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.count(target - nums[i])) return {i, m[target - nums[i]]};
            m[nums[i]] = i; //m[元素值] = 下标
        }

        return {};
    }
};

int main(int argc, char **argv)
{
    vector<int> vec{2,7,11,15};
    Solution *so = new Solution();
    vector<int> ret = so->twoSum(vec, 13);
    for(auto i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}