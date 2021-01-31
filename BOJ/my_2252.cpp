// 위상정렬

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

int n, m, indegree[32010];
vector<int> adj[32010];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (--indegree[next] == 0)
                q.push(next);
        }
    }
    cout << '\n';

    return 0;
}