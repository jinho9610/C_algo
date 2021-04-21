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

int n, m, v, isVisited[1001];
vector<int> adj[1001];

void dfs(int start)
{
    if (isVisited[start]) // 이미 방문한적있다면
        return;           // 돌아가

    isVisited[start] = true; // 방문한다
    cout << start << ' ';    // 방문한 노드 출력

    for (int i = 0; i < adj[start].size(); i++) // 인접 노드 중
    {
        int next = adj[start][i]; // 다음 인접 노드
        if (!isVisited[next])     // 방문한적이 없는 노드라면
            dfs(next);
    }
}

void bfs(int start)
{
    memset(isVisited, 0x00, sizeof(isVisited));

    queue<int> q;
    q.push(start);
    isVisited[start] = true;
    cout << start << ' ';

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];

            if (!isVisited[next])
            {
                cout << next << ' ';
                q.push(next);
                isVisited[next] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(v);
    cout << '\n';
    bfs(v);

    return 0;
}