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

int f, s, g, u, d, visited[1000001];

ll dfs(int x, ll cnt)
{
    // 1. 체크인
    visited[x] = cnt;

    // 2. 목적지에 왔는지
    if (x == g)
        return visited[x];

    // 3. 순회
    for (int i = 0; i < 2; i++)
    {
        if (i == 0) // 올라가는 경우
            if (x + u <= f && !visited[x + u])
                return dfs(x + u, cnt + 1);
        if (i == 1) // 내려가는 경우
            if (x - d > 0 && !visited[x - d])
                return dfs(x - d, cnt + 1);
    }

    return -1;
}

int bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == g)
            return visited[now];

        for (int i = 0; i < 2; i++)
        {
            if (i == 0)
            {
                int nxt = now + u;
                if (nxt <= f && visited[nxt] == -1)
                {
                    visited[nxt] = visited[now] + 1;
                    q.push(nxt);
                }
            }
            else
            {
                int nxt = now - d;
                if (nxt > 0 && visited[nxt] == -1)
                {
                    visited[nxt] = visited[now] + 1;
                    q.push(nxt);
                }
            }
        }
    }

    return -5;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> f >> s >> g >> u >> d;

    memset(visited, 0xff, sizeof(visited));

    ll val = bfs(s);

    if (val == -5)
        cout << "use the stairs" << endl;
    else
        cout << val << endl;

    return 0;
}