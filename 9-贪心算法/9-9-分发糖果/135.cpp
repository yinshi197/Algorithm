#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> candy(size, 1); //初始化每人一个糖果
        int ret = 0;
        
        for(int i = 1; i < size; i++)
        {
            if(ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }

        for(int i = size - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
            {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        for(auto i : candy) ret += i;

        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<int> ratings = {1, 2, 2, 2, 2};
    Solution *so = new Solution();
    int ret = so->candy(ratings);

    cout << ret << endl;

    return 0;
}