#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while(true)
        {
            n = getSum(n);
            if(n == 1) return true;
            if(s.count(n)) return false;
            s.insert(n);        
        }

        return false;
    }

    int getSum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }
};

int main(int argc, char **argv)
{
    Solution *so = new Solution();
    bool ret = so->isHappy(2);
    cout << ret << endl;
    return 0;
}