/* BOJ 13911 �� ���ϱ� */
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

void dijkstra_mac(int start) // �Ƶ������ ���ͽ�Ʈ��
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

void dijkstra_star(int start) // ��Ÿ������ ���ͽ�Ʈ�� 
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
		edges[v].push_back({ u,w }); // ����� ���� ����
	}
	
	// ���� �Ƶ�����, ���� ��Ÿ����
	// ���� �Ƶ������ ��� �Ƶ�������� �Ÿ��� 0�� �Ƶ�����
	// ���� ��Ÿ������ ��� ��Ÿ�������� �Ÿ��� 0�� ��Ÿ����
	// ������ �����ϴ� v���� ������ ������ ���ϱ� ���� v + 1, v + 2 �ε��� ���
	dummy_mac = v + 1, dummy_star = v + 2;

	// �Ƶ����� ���� �Է� �ޱ�
	cin >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		is_house[a] = false;
		// ���� �Ƶ������ ��¥ �Ƶ����� �� ���� ����
		edges[dummy_mac].push_back({ a, 0 });
		edges[a].push_back({ dummy_mac, 0 });
	}

	// ��Ÿ���� ���� �Է¹ޱ�
	cin >> s >> y;
	for (int i = 0; i < s; i++)
	{
		int a;
		cin >> a;
		is_house[a] = false;
		// ���� ��Ÿ������ ��¥ ��Ÿ������ ���� ����
		edges[dummy_star].push_back({ a, 0 });
		edges[a].push_back({ dummy_star, 0 });
	}

	// �Ƽ��� ����
	dijkstra_mac(dummy_mac);
	for (int i = 1; i <= v; i++)
	{
		if (!is_house[i])
			continue;

		if (dist[i][0] <= x) // �Ƽ���
			is_mac_or_star[i][0] = true;
	}

	// ������ ����
	dijkstra_star(dummy_star);
	for (int i = 1; i <= v; i++)
	{
		if (!is_house[i])
			continue;

		if (dist[i][1] <= y) // ������ 
			is_mac_or_star[i][1] = true;
	}

	int ans = INF;
	for (int i = 1; i <= v; i++)
	{
		if (!is_house[i])
			continue;

		if (is_mac_or_star[i][0] && is_mac_or_star[i][1]) // �Ƽ����̸鼭 �������̸�
			ans = min(ans, dist[i][0] + dist[i][1]); // �� ���� �ּ��� ��쿡 ���ؼ� �ľ�
	}

	if (ans == INF) // ������ �����ϴ� ���� ���� ���
		cout << -1 << endl;

	else cout << ans << endl;

	return 0;
}
