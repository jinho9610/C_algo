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

int n, m, k;
const int INF = 1e9;
vector<pair<int, int>> edges[1001];
priority_queue<int> paths[1001]; // 정점별로 경로를 보유함 // 얘는 맥스 힙

struct pq_cmp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first > p2.first;
    }
};

void kth_dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, pq_cmp> pq; // 최소 힙

    pq.push(make_pair(0, 1));
    paths[1].push(0);

    while (!pq.empty())
    {
        int distance = pq.top().first, now = pq.top().second;
        pq.pop();

        for (auto edge : edges[now])
        {
            int next = edge.first;
            int cost = distance + edge.second; // "next" 노드로의 현재까지의 최단거리

            if (paths[next].size() < k)        // 다음 정점이 아직 k개의 경로를 보유하지 않았다면
                paths[next].push(cost);        // 경로 k를 찾아서 차곡차곡 넣는다
            else if (paths[next].top() > cost) // 찾은 k개의 경로 중 가장 긴 경로보다 짧은 경로 발견하면
            {
                paths[next].pop();
                paths[next].push(cost);
            }
            else
                continue; // k개의 경로를 찾는 과정에 참여하지 못하는 경우에는 pq에 넣지 않는다

            pq.push(make_pair(cost, next));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
    }

    kth_dijkstra();

    for (int i = 1; i <= n; i++)
    {
        if (paths[i].size() == k) // 경로 k 찾았으면
            cout << paths[i].top() << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}