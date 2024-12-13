#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        int index = strNum.size();

        for(int i = strNum.size() - 1; i > 0; i--)
        {
            if(strNum[i - 1] > strNum[i]) 
            {   
                index = i;
                strNum[i - 1]--;
            }
        }

        for(int i = index; i < strNum.size(); i++)
        {
            strNum[i] = '9';
        }

        return stoi(strNum);
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, T;
    cin >> T;
    Solution *so = new Solution();
    while(T--)
    {
        cin >> n;
        cout << so->monotoneIncreasingDigits(n) << "\n";
    }

    return 0;
}