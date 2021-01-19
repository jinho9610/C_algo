#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<vector<pair<int, int>>> graph;
int n, m, start;
vector<int> dist;

struct cmp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first > p2.first;
    }
};

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < distance)
            continue;

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
    cin >> n >> m;
    cin >> start;

    graph.resize(n + 1);
    dist.resize(n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    dijkstra(start);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }

    return 0;
}