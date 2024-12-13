#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int n, k;
    vector<int> vec;

    bool isVaild(int val)
    {
        if(check(val, 0) || check(val, 1)) return true;
        return false;
    }

    bool check(int val, int index)
    {
        int count = 0;
        if(index == 0)
        {
            count = 0;
            for(int i = 0; i < n; i++)
            {
                if(vec[i] <= val)
                {
                    if(i != n) count += 2;
                    else count++;
                    i++;
                }
            }
        }
        else
        {
            count = 1;
            for(int i = 1; i < n; i++)
            {
                if(vec[i] <= val)
                {
                    if(i != n) count += 2;
                    else count++;
                    i++;
                }
            }
        }

        return count >= k;
    }

    void slove()
    {
        cin >> n >> k;
        vec.resize(n, 0);
        int l = 0, r = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> vec[i];
            r = max(vec[i], r);
        }

        while(l != r -1)
        {
            int mid = l + (r - l) / 2;
            if(isVaild(mid)) r = mid;
            else l = mid;
        }

        cout << r << "\n";
    }

};

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    Solution *so = new Solution();
    so->slove();

    return 0;
}