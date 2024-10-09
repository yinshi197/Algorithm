#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        if(fruits.size() == 1)
        {
            return 1;
        }
        int n = fruits.size() - 1;
        int left = 0;
        int c1 = fruits[0];
        int c2 = -1;
        int sum = 1;
        int lastLenth1 = 1;
        int lastLenth2 = 1;
        int ret = 0;
        for(int i = 1; i <= n; i++)
        {
            if(fruits[i] == c1)
            {
                sum++;
                if(i + 1 < n && fruits[i + 1] == c1)
                    {
                        lastLenth1++;
                        lastLenth2 = 0;
                    }
                    
            }
            else if(fruits[i] == c2 || c2 == -1)
            {
                sum++;
                c2 = fruits[i];
                if(i + 1 < n && fruits[i + 1] == c2)
                {
                    lastLenth2++;
                    lastLenth1 = 0;
                }
            }
            else
            {
                if(fruits[i - 1] == c1)
                {
                    sum = lastLenth1;
                    sum++;
                    c2 = fruits[i];
                    lastLenth1 = 1;
                    lastLenth2 = 0;
                }
                else
                {
                    sum = lastLenth2;
                    sum++;
                    c1 = c2;
                    c2 = fruits[i];
                    lastLenth1 = 0;
                    lastLenth2 = 1;
                    if(i + 1 < n && fruits[i + 1] == c2)
                    {
                        lastLenth2++;
                        lastLenth1 = 0;
                    }    
                }
                    
            }

            ret = ret < sum ? sum : ret;
        }

        return ret;
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
