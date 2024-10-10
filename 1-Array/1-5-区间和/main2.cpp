//二维前缀和
#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    vector<int> vecn(n);    //行
    vector<int> vecm(m);    //列
    int result = INT32_MAX;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
            sum += vec[i][j];
        }
        vecn[i] = sum;
    }

    int summ = 0;
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            summ += vec[i][j];
        }
        vecm[j] = summ;
    }

    for(int i = 0; i < n - 1; i++)
    {
        int temp = abs(sum - vecn[i] * 2);
        result = min(result,temp);
    }

    for(int j = 0; j < m - 1; j++)
    {
        int temp = abs(sum - vecm[j] * 2);
        result = min(result,temp);
    }

    cout << result;
    return 0;

}
