#include <bits/stdc++.h>
using namespace std;

int n, m, T;
int a[999][999], b[999][999];
int px[4], py[4];

void dfs(int x, int y, int index)
{
    b[x][y] = index;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + px[i];
        int ny = y + py[i];
        if(nx > 0 && nx <= n && ny > 0 && ny <= m & !b[nx][ny])
        {
            if(a[x][y] != a[nx][ny]) dfs(nx, ny, index);
        }
    }
}

int main()
{
    px[0] = 0, px[1] = 0, px[2] = 1, px[3] = -1;
    py[0] = 1, py[1] = -1, py[2] = 0, py[3] = 0;

    cin >> n >> m >> T;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    int index = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!b[i][j]) dfs(i, j, index++);
        }
    }

    for(int i = 0, x1, y1, x2, y2; i < T; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if(b[x1][y1] == b[x2][y2]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}