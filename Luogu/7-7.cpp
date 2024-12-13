#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int n;
    vector<int> vec;
    vector<int> vec1;
    vector<int> vec2;

    int way1()
    {
        vec1 = vec;
        vec1.erase(vec1.begin());
        return vec1[0] ^ vec1.size();
    }

    int way2()
    {
        vec2 = vec;
        for(int i = 0; i < vec2.size(); i++)
        {
            if(vec2[i] == 1) vec2.erase(vec2.begin() + i);
            else vec2[i]--;
        }

        return vec2[0] ^ vec2.size();
    }

    void slove()
    {
        cin >> n;
        vec.resize(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        int ret = 0;
        sort(vec.begin(), vec.end(), greater<int>());
        for(int i = 0; i < n - 1; i++)
        {
            int a = way1(), b = way2();
            if(a > b)
            {
                vec = vec1;
                ret += a;
            }
            else
            {
                vec = vec2;
                ret += b;
            }
        }

        cout << ret << "\n";
    }

};

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    Solution *so = new Solution();
    so->slove();

    return 0;
}