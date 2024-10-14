#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> reslut_set;
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for(auto num : nums2)
        {
            if(num_set.count(num))  reslut_set.insert(num);
        }
        vector<int> ret(reslut_set.begin(), reslut_set.end());
        return ret;
    }
};

int main(int argc, char **argv)
{
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};
    Solution *so = new Solution();
    vector<int> ans = so->intersection(nums1, nums2);
    for(auto i : ans)
    {
        cout << i << " ";
        cout << endl;
    }
    return 0;
}