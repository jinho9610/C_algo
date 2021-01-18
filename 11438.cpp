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

// ROOT = 1

int n, m, depth[100010], ancestor[100010][18];
vector<int> adj[100010];
bool visited[100010];

void dfs(int parent, int cur, int param_depth)
{
    if (visited[cur])
        return;

    visited[cur] = true; // 1. 체크인
    depth[cur] = param_depth;
    ancestor[cur][0] = parent;
    for (int i = 0; i < adj[cur].size(); i++)
        dfs(cur, adj[cur][i], param_depth + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // 양방향 연결
    }

    // LCA를 위한 자료 수집 : 깊이, 1/2/4/... 조상
    dfs(1, 1, 1)

        return 0;
}