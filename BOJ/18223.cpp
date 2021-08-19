/* BOJ 18223 민준이와 마산 그리고 건우 */
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

const int INF = 1e9;
int v, e, p, dist[5001], visited[5001];
vector<pair<int, int>> edges[5001];

struct cmp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

void dijkstra(int start)
{
    for (int i = 1; i <= v; i++)
        dist[i] = INF;
    memset(visited, 0x00, sizeof(visited));

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        if (visited[cur])
            continue;
        visited[cur] = true;

        for (auto edge : edges[cur])
        {
            int next = edge.first;
            int cost = edge.second;

            if (dist[next] > distance + cost)
            {
                dist[next] = distance + cost;
                pq.push({next, dist[next]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    cin >> v >> e >> p;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c}); // 양방향 간선
    }

    dijkstra(1);
    int dist_to_v = dist[v];
    int dist_to_p = dist[p];
    dijkstra(p);
    int dist_from_p_to_v = dist[v];

    if (dist_to_p + dist_from_p_to_v <= dist_to_v)
        cout << "SAVE HIM" << endl;
    else
        cout << "GOOD BYE" << endl;

    return 0;
}