/* BOJ 13911 집 구하기 */
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
int v, e, dist[10003][2], m, s, x, y;
bool visited[10003], is_house[10003], is_mac_or_star[10003][2];
vector<pair<int, int>> edges[10003];
vector<int> macs, stars;
int dummy_mac, dummy_star;

struct cmp
{
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		return p1.second > p2.second;
	}
};

void dijkstra_mac(int start) // 맥도날드용 다익스트라
{
	memset(visited, 0x00, sizeof(visited));
	for (int i = 1; i <= v; i++)
		dist[i][0] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ start, 0 });
	dist[start][0] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().first, distance = pq.top().second;
		pq.pop();

		if (visited[cur])
			continue;

		visited[cur] = true;

		for (auto edge : edges[cur])
		{
			int next = edge.first, cost = edge.second;

			if (distance + cost < dist[next][0])
			{
				dist[next][0] = distance + cost;
				pq.push({ next, dist[next][0] });
			}
		}
	}
}

void dijkstra_star(int start) // 스타벅스용 다익스트라 
{
	memset(visited, 0x00, sizeof(visited));
	for (int i = 1; i <= v; i++)
		dist[i][1] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ start, 0 });
	dist[start][1] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().first, distance = pq.top().second;
		pq.pop();

		if (visited[cur])
			continue;

		visited[cur] = true;

		for (auto edge : edges[cur])
		{
			int next = edge.first, cost = edge.second;

			if (distance + cost < dist[next][1])
			{
				dist[next][1] = distance + cost;
				pq.push({ next, dist[next][1] });
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

	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		is_house[i] = true;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({ v,w });
		edges[v].push_back({ u,w }); // 양방향 통행 가능
	}
	
	// 더미 맥도날드, 더미 스타벅스
	// 더미 맥도날드는 모든 맥도날드와의 거리가 0인 맥도날드
	// 더미 스타벅스는 모든 스타벅스와의 거리가 0인 스타벅스
	// 기존에 존재하는 v개의 노드와의 간섭을 피하기 위해 v + 1, v + 2 인덱스 사용
	dummy_mac = v + 1, dummy_star = v + 2;

	// 맥도날드 정보 입력 받기
	cin >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		is_house[a] = false;
		// 더미 맥도날드와 진짜 맥도날드 간 간선 연결
		edges[dummy_mac].push_back({ a, 0 });
		edges[a].push_back({ dummy_mac, 0 });
	}

	// 스타벅스 정보 입력받기
	cin >> s >> y;
	for (int i = 0; i < s; i++)
	{
		int a;
		cin >> a;
		is_house[a] = false;
		// 더미 스타벅스와 진짜 스타벅스간 간선 연결
		edges[dummy_star].push_back({ a, 0 });
		edges[a].push_back({ dummy_star, 0 });
	}

	// 맥세권 조사
	dijkstra_mac(dummy_mac);
	for (int i = 1; i <= v; i++)
	{
		if (!is_house[i])
			continue;

		if (dist[i][0] <= x) // 맥세권
			is_mac_or_star[i][0] = true;
	}

	// 스세권 조사
	dijkstra_star(dummy_star);
	for (int i = 1; i <= v; i++)
	{
		if (!is_house[i])
			continue;

		if (dist[i][1] <= y) // 스세권 
			is_mac_or_star[i][1] = true;
	}

	int ans = INF;
	for (int i = 1; i <= v; i++)
	{
		if (!is_house[i])
			continue;

		if (is_mac_or_star[i][0] && is_mac_or_star[i][1]) // 맥세권이면서 스세권이면
			ans = min(ans, dist[i][0] + dist[i][1]); // 그 합이 최소인 경우에 대해서 파악
	}

	if (ans == INF) // 조건을 만족하는 집이 없는 경우
		cout << -1 << endl;

	else cout << ans << endl;

	return 0;
}
