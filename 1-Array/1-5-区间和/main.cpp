#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> st(n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
        st[i] = sum;
    }

    int a, b;
    while(cin >> a >> b)
    {
        if(a == 0 && b == 0) break;
        if(a == 0)
        {
            cout << st[b] << endl;
        }
        else
        {
            cout << st[b] - st[a - 1] << endl;
        }    
    }

    return 0;

}
