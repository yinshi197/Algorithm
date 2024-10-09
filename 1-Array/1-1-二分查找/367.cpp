#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if((long long)mid * mid > num)
            {
                right = mid - 1;
            }
            else if((long long)mid * mid < num)
            {
                left = mid + 1;
            }
            else return true;     
        }

        return false;
    }

    bool isPerfectSquare2(int num) {
        int temp = 1;
        while(num >0)
        {
            num -= temp;
            temp += 2;
        }

        return num == 0;
    }
};

int main(int argc, char **argv)
{
    bool ret;
    Solution *so = new Solution();
    ret = so->isPerfectSquare2(12);
    cout << ret << endl;

    return 0;
}
