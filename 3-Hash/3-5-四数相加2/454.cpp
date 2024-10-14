#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        for(int a : nums1)
        {
            for(int b : nums2)
            {
                m[a + b]++;
            }
        }

        int count = 0;
        for(int c : nums3)
        {
            for(int d : nums4)
            {
                if(m.count(0 - c - d))
                {
                    count += m[0 - c - d];
                }
            }
        }

        return count;
    }
};

int main(int argc, char **argv)
{
    vector<int> vec1{-1,-1};
    vector<int> vec2{-1,1};
    vector<int> vec3{-1,1};
    vector<int> vec4{1,-1};
    Solution *so = new Solution();
    int ret = so->fourSumCount(vec1, vec2, vec3, vec4);
    cout << ret << endl;
    return 0;
}