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

#define INF 1e9

int n, m, s, d;
ll min_cost;
vector<pair<int, int>> edges[501];
bool isNotUsable[501][501]; // (i, j)가 true이면 최단 거리를 구성하는 도로이므로, 사용할 수 없음
vector<int> dist;

struct cmp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first > p2.first; // 최소힙 구현
    }
};

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // 최소힙. (cost, 노드 번호) 삽입
    dist[start] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < distance)
            continue;

        for (auto edge : edges[now])
        {
            if (isNotUsable[now][edge.first] == true)
                continue; // 최단 경로를 구성하는 경우에는 그냥건너뜀

            int next = edge.first;
            int cost = edge.second + distance;

            if (dist[next] > cost)
            {
                dist[next] = cost;
                pq.push(make_pair(cost, next));
                isNotUsable[now][next] = true; // 최단경로를 구성하는 간선 표시
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        cin >> s >> d;

        memset(edges, 0, sizeof(edges));
        memset(isNotUsable, false, sizeof(isNotUsable));
        dist.resize(n + 1, INF);

        for (int i = 0; i < m; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            edges[u].push_back(make_pair(v, p));
        }

        dijkstra(s);
        for (int i = 0; i <= n + 1; i++)
            dist[i] = INF;
        dijkstra(s);

        cout << dist[d] << '\n';
    }
    return 0;
}