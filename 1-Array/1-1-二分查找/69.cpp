#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //简单的二分法求解
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;
        while(left <= right)
        {
            long long mid = (left + right) / 2;
            if(mid * mid > x)
            {
                right = mid - 1;
            }
            else
            {
                left =  mid + 1;
            }
        }

        return right;
    }

    //牛顿迭代求平方根
    double mySqrt2(int x)
    {
        //float后加f转换成double类型
        if(x == 0) return 0; 
        float result = x; 
        float xhalf = 0.5f*result; 
        int i = *(int*)&result; 
        
        i = 0x5f3759df - (i>>1); 
        result = *(float*)&i; 
        result = result*(1.5f-xhalf*result*result);
        result = result*(1.5f-xhalf*result*result);
        return 1.0f/result; 
    }
};

int main(int argc, char **argv)
{
    int ret = -1;
    Solution *so = new Solution();
    ret = so->mySqrt(2147395599);
    cout << ret << endl;

    return 0;
}
