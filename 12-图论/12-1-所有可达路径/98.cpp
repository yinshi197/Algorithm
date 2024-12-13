#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m, s, t;
vector<vector<int>> ret;
vector<int> path;

void dfs(const vector<vector<int>>& graph, int x, int n)
{
    //终止条件
    if(x == n)
    {
        ret.push_back(path);
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(graph[x][i]) //x指向的节点就是i
        {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    while(m--)
    {
        cin >> s >> t;
        graph[s][t] = 1;
    }

    //所有路径都是从节点1开始
    path.push_back(1);
    dfs(graph, 1, n);

    if(ret.size() == 0) cout << -1 << "\n";
    for(const vector<int>& vec : ret)
    {
        for(int i = 0; i < vec.size() - 1; i++)
        {
            cout << vec[i] << " ";
        }
        cout << vec[vec.size() - 1] << "\n";
    }

    return 0;
}