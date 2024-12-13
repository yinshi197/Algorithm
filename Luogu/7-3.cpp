#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int n, m;
    vector<int> vec;

    void slove()
    {
        cin >> n >> m;
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