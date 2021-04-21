// 풀이에 사용된 알고리즘:

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;

int n, m, visited[1001];
vector<int> adj[1001];

void dfs(int node)
{
    if (visited[node])
        return;

    visited[node] = true;

    for (auto next : adj[node])
    {
        if (!visited[next])
            dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 양방햔 간선
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            res++;
            dfs(i);
        }
    }

    cout << res << endl;

    return 0;
}