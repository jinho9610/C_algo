/* BOJ 20010 악덕 영주 혜유 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

const int INF = 1e9;
int n, k, p[1000];
vector<pair<pair<int, int>, int>> edges;
vector<pair<int, int>> adj[1000];
bool visited[1000];
int tmp_len = 0;

void dfs(int cur, int len)
{
	if (visited[cur])
		return;

	visited[cur] = true;
	for (auto next : adj[cur])
		dfs(next.first, len + next.second);

	tmp_len = max(tmp_len, len);
}

int find_parent(int x)
{
	if (x == p[x])
		return x;

	return p[x] = find_parent(p[x]);
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);
	
	if (a > b)
		p[a] = b;
	else
		p[b] = a;
}

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	return p1.second < p2.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		p[i] = i;

	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ {a, b}, c });
	}

	sort(edges.begin(), edges.end(), cmp);

	int min_cost = 0; // 모든 마을을 연결하는 최소 비용
	for (auto edge : edges)
	{
		if (find_parent(edge.first.first) == find_parent(edge.first.second))
			continue;

		union_parent(edge.first.first, edge.first.second);

		adj[edge.first.first].push_back({ edge.first.second, edge.second });
		adj[edge.first.second].push_back({ edge.first.first, edge.second });

		min_cost += edge.second;
	}

	int max_len = 0;
	for (int i = 0; i < n; i++)
	{
		if (adj[i].size() > 0)
		{
			memset(visited, 0x00, sizeof(visited));
			tmp_len = 0;
			dfs(i, 0);
			max_len = max(max_len, tmp_len);
		}
	}

	cout << min_cost << endl;
	cout << max_len << endl;

	return 0;
}