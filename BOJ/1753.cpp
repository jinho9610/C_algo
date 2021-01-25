// 풀이에 사용된 알고리즘: 다익스트라

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

struct cmp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first > p2.first;
    }
};

const int INF = 1e9;
int V, E, start;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start)); // 어떤 노드까지의 거리를 (거리, 노드번호) 쌍으로 삽입

    while (!pq.empty()) // 큐가 빌 때까지
    {
        int distance = pq.top().first, now = pq.top().second;
        pq.pop();

        // if (dist[now] < distance)
        //     continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = distance + graph[now][i].second;
            if (cost < dist[graph[now][i].first])
            {
                dist[graph[now][i].first] = cost;
                pq.push(make_pair(cost, graph[now][i].first));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E >> start;

    graph.resize(V + 1);
    dist.resize(V + 1, INF);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    dijkstra(start);

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}