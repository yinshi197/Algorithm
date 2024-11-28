#include <iostream>
#include <string>
using namespace std;

string func(long long n, long long m, long long k, long long p)
{
    if(p < n) return "Together";
    if(p / n + k <= m) return "Together";
    if(k == 1 && p + k <= n * m) return "Together";
    
    if(k > m) return "Divide";
    
    if(k <= m && p / m < n) return "Chance";

    return "Chance";
}

int main()
{
    long long n, m, k, p;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> n >> m >> k >> p;
        string ret = func(n, m, k, p);
        cout << ret << endl;
    }

    return 0;
}