/* BOJ 1916 최소 비용 구하기 */
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
int n, m, dist[1001];
bool visited[1001];
vector<pair<int, int>> edges[1001];

struct cmp
{
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		return p1.second > p2.second;
	}
};

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().first, distance = pq.top().second;
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

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b, c });
	}

	int s, d;
	cin >> s >> d;
	
	dijkstra(s);

	cout << dist[d] << endl;

	return 0;
}
