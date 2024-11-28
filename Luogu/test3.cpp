#include <iostream>
#include <string>
using namespace std;

int func(int k)
{
    long long r1, r2;
    r1 = k * 2 + 1;
    int ret = 0;
    while(r1 % 2 != 0 && ret < k)
    {
        r2 = (r1 + 1) / 2;
        r1 = r1 * r2;
        ret++;
    }

    return ret;
}

int main()
{
    int T, k;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> k;
        int ret = func(k);
        if(ret == 10) 
            cout << "NO!";
        else cout << ret;
    }

    return 0;
}