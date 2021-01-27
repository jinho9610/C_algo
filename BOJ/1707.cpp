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

int k, color[20001];
vector<int> adj[20001];

bool bfs(int node)
{
    queue<int> q;
    color[node] = 1;
    q.push(node);

    while (!q.empty())
    {
        int now = q.front();
        int cur_c = color[now]; // 현재 노드의 색
        q.pop();

        for (int i = 0; i < adj[now].size(); i++)
        {
            int nxt = adj[now][i];

            if (color[nxt] == cur_c)
                return false;

            if (color[nxt] == 0)
            {
                color[nxt] = -cur_c;
                q.push(nxt);
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

    for (int t = 0; t < k; t++)
    {
        memset(color, 0x00, sizeof(color));
        memset(adj, 0x00, sizeof(adj));

        int v, e; // v - 노드 개수, e - 간선 개수
        cin >> v >> e;

        for (int i = 0; i < e; i++) // 간선 정보 입력
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool f = true;
        for (int i = 1; i <= v; i++)
        {
            if (color[i] == 0)
                f = bfs(i);

            if (f == false)
                break;
        }

        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}