#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for(auto val : bills)
        {
            if(val == 5) five++;
            
            if(val == 10)
            {
                if(five > 0) five--, ten++;
                else return false;    
            }

            if(val == 20)
            {
                if(ten > 0 && five > 0) five--, ten--;
                else if(five > 3) five -= 3;
                else return false;
            }
        }
        
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> bills = {5,5,10,10,20};  //5,5,5,10,20、5,5,10,10,20
    Solution *so = new Solution();
    bool ret = so->lemonadeChange(bills);

    cout << ret << endl;

    return 0;
}