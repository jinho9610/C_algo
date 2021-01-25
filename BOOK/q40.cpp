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

const int INF = 1e9;
int n, m, dist[20001];
vector<pair<int, int>> edges[20001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int now = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (dist[now] < distance)
            continue;

        for (auto edge : edges[now])
        {
            int next = edge.first;
            int cost = distance + edge.second;

            if (cost < dist[next])
            {
                dist[next] = cost;
                pq.push({-cost, next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    fill(dist, dist + 20001, INF); // dist 벡터 초기화

    for (int i = 0; i < m; i++) // 양방향 통로 정보 입력받기
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back({b, 1});
        edges[b].push_back({a, 1});
    }

    dijkstra(1);

    int place = 0, max_val = 0, cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (dist[i] > max_val)
        {
            cnt = 0;
            max_val = dist[i];
            place = i;
        }
        if (dist[i] == max_val)
            cnt++;
    }

    cout << place << ' ' << dist[place] << ' ' << cnt << endl;

    return 0;
}