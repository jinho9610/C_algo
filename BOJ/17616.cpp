/* BOJ 17616 등수 찾기 */
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

int n, m, x, visited[100001];
vector<int> adj[100001], reverse_adj[100001];
int cnt = -1, reverse_cnt = -1;

void dfs(int cur)
{
    if (visited[cur])
        return;

    visited[cur] = true;
    cnt++;

    for (int next : adj[cur])
        dfs(next);
}

void reverse_dfs(int cur)
{
    if (visited[cur])
        return;

    visited[cur] = true;
    reverse_cnt++;

    for (int next : reverse_adj[cur])
        reverse_dfs(next);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);         // 정방향 간선
        reverse_adj[b].push_back(a); // 역방향 간선
    }

    dfs(x);

    memset(visited, 0x00, sizeof(visited));
    reverse_dfs(x);

    cout << reverse_cnt + 1 << ' ' << n - cnt << endl;

    return 0;
}