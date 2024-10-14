#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() > nums2.size()) return intersect(nums2, nums1);

        unordered_map<int, int> m;
        for(int num : nums1)  ++m[num];
        vector<int> ret;
        for(int num : nums2)
        {
            if(m.count(num))
            {
                ret.push_back(num);
                m[num]--;
                if(m[num] == 0)
                {
                    m.erase(num);
                }
            }
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    vector<int> nums1{4,9,4,5};
    vector<int> nums2{9,4,9,8,4};
    Solution *so = new Solution();
    vector<int> ans = so->intersect(nums1, nums2);
    for(auto i : ans)
    {
        cout << i << " ";
        cout << endl;
    }
    return 0;
}