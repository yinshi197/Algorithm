#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

//循环不变量原则，循环的区间里面的值不能改变。
//边界条件统一
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int startx = 0; int starty = 0;
        int loop = n / 2;   //循环次数，n为奇数中间为一格空格
        int mid = n / 2;
        int count = 1;  //计数器
        int offset = 1; //遍历每条边的偏移量
        int i,j;
        while(loop--)
        {
            i = startx;
            j = starty;

            //模拟填充上边(左闭右开)
            for(j; j < n - offset; j++)
            {
                ret[i][j] = count++;
            }

            //模拟填充右边(左闭右开)
            for(i; i < n - offset; i++)
            {
                ret[i][j] = count++;
            }

            //模拟填充下边(左闭右开)
            for(j; j > startx; j--)
            {
                ret[i][j] = count++;
            }

            //模拟填充左边(左闭右开)
            for(i; i > startx; i--)
            {
                ret[i][j] = count++;
            }

            //执行完一圈，更新控制参数
            offset++;
            startx++;
            starty++;
        }

        if(n % 2)
        {
            ret[mid][mid] = count;
        }

        return ret;
    }
};

int main(int argc, char **argv)
{
    int ret;
    vector<vector<int>> ans;
    Solution *so = new Solution();
    ans = so->generateMatrix(3);
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout << j << "\t";
        }
        cout << "\n";
    }
    return 0;
}
