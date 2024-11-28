#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> n >> k;
        vector<int> vec(n);
        int max = 0;
        long ret = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> vec[i];
            if(vec[i] > max) max = vec[i];
            ret += max;
        }
        if(k > 0)
         cout << n * max << endl;
        else cout << ret << endl;
    }

    return 0;
}