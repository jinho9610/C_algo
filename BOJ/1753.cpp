/* BOJ 1753 �ִ� ��� */
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
	// pq�� ���� ���� (a, b)�� ��������->a�� ����
	// (������� ������) �ִ� ����� b���� �ǹ�
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int distance = pq.top().second;
		pq.pop();

		if (visited[cur]) // ���� ��忡 ���� �ִ� ��� ������ �̹� ����ƴٸ�
			continue;

		visited[cur] = true;

		for (auto edge : edges[cur]) // ���� ���� ����� ��� ���� �ľ�
		{
			// (���� ���� ������ ��������) cur->next�� ���� ����� cost��
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
		edges[u].push_back({ v,w }); // ���� �׷���
	}

	for (int i = 1; i <= v; i++)
		dist[i] = INF; // dist �迭 �ʱ�ȭ

	dijkstra(s);

	for (int i = 1; i <= v; i++)
		if (dist[i] == INF)
			cout << "INF" << endl;
	else cout << dist[i] << endl;

	return 0;
}
