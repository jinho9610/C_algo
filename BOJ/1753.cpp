/* BOJ 1753 최단 경로 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const int INF = 1e9;
int v, e, s, dist[20001];
bool visited[20001];
vector<pair<int, int>> edges[20001];

struct cmp
{
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		return p1.second > p2.second;
	}
};

void dijkstra(int start)
{
	// pq에 들어가는 원소 (a, b)는 시작지점->a로 가는
	// (현재까지 밝혀진) 최단 비용이 b임을 의미
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int distance = pq.top().second;
		pq.pop();

		if (visited[cur]) // 현재 노드에 대한 최단 비용 연산이 이미 진행됐다면
			continue;

		visited[cur] = true;

		for (auto edge : edges[cur]) // 현재 노드와 연결된 모든 간선 파악
		{
			// (현재 간선 정보를 바탕으로) cur->next로 가는 비용이 cost임
			int next = edge.first;
			int cost = edge.second;

			if (distance + cost < dist[next])
			{
				dist[next] = distance + cost;
				pq.push({ next, dist[next] });
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

	cin >> v >> e >> s;
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({ v,w }); // 방향 그래프
	}

	for (int i = 1; i <= v; i++)
		dist[i] = INF; // dist 배열 초기화

	dijkstra(s);

	for (int i = 1; i <= v; i++)
		if (dist[i] == INF)
			cout << "INF" << endl;
	else cout << dist[i] << endl;

	return 0;
}
