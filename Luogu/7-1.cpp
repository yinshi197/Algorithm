#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    int n, index, ret = 0;
    cin >> n;
    vector<int> vec(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), greater<int>());
    int count = ceil(n * 0.3);
    index = vec[count - 1];

    if(index < 40) index = 40;
    for(auto i : vec)
    {
        if(i >= index) ret++;
    }
    cout << ret << endl;
    return 0;
}