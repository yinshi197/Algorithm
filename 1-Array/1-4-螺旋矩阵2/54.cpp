#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty())
            return ans;
        int u = 0;  //上边界
        int d = matrix.size() - 1;  //下边界
        int l = 0;  //左边界
        int r = matrix[0].size() - 1;   //右边界
        while(true)
        {
            //上行从左往右，遍历结束后更新u节点
            for(int i = l; i <= r; i++) ans.push_back(matrix[u][i]);
            if(++u > d) break;

            //右行从上往下，遍历结束后更新r节点
            for(int i = u; i <= d; i++) ans.push_back(matrix[i][r]);
            if(--r < l) break;

            //下行从右往左，遍历结束后更新d节点
            for(int i = r; i >= l; i--) ans.push_back(matrix[d][i]);
            if(--d < u) break;

            //左行从下往上，遍历结束后更新l节点
            for(int i = d; i >= u; i--) ans.push_back(matrix[i][l]);
            if(++l > r) break;
        }
        
        return ans;
    }
};

int main(int argc, char **argv)
{
    vector<int> ret;
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};
    Solution *so = new Solution();
    ret = so->spiralOrder(vec);
    for(auto i : ret)
    {
        cout << i << " ";
    }
    return 0;
}
