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

int red = 0;
int k, v, e, visited[20001];
vector<int> adj[20001];

bool bfs(int start)
{
    queue<int> q;
    visited[start] = 0; // 시작점은 빨간색으로 색칠
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int cur_color = visited[cur];

        for (auto next : adj[cur])
        {
            if (visited[next] == -1) // 아직 색칠된 적이 없다면
            {
                visited[next] = !cur_color; // 현재 노드와 다른 색으로 색칠
                q.push(next);
            }
            else
            {
                if (visited[next] == cur_color)
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> v >> e;
        memset(adj, 0x00, sizeof(adj));
        memset(visited, 0xff, sizeof(visited));

        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool flag = true;
        for (int i = 1; i <= v; i++)
        {
            if (visited[i] == -1)
                flag = bfs(i);

            if (!flag)
                break;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}