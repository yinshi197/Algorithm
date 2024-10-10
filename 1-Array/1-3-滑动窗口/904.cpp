#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

class Solution { 
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        vector<int> Count(fruits.size());   //某种水果采摘个数
        int kind = 0;
        int ans = 0;
        for(int i = 0; i < fruits.size(); i++)
        {
            if(Count[fruits[i]] == 0)
            {
                kind++;
            }

            Count[fruits[i]]++;

            while(kind > 2)
            {
                Count[fruits[left]]--;  //向前滑动
                if(Count[fruits[left]] == 0)
                {
                    kind--;
                }
                left++; //窗口是每次向前滑动一格
            }

            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};

int main(int argc, char **argv)
{
    int ret;
    Solution *so = new Solution();
    vector<int> vec = {1,0,29,29,29,29,29,29,0,0,29,8,8,29,8,29,8,8,15,8,8,15,15,8,15,15,8,8,7,5};
    ret = so->totalFruit(vec);
    cout << ret << endl;
    return 0;
}
