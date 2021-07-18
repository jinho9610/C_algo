/* BOJ 1944 복제 로봇 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <unordered_set>

#define endl '\n'

using namespace std;

typedef long long ll;

int n, k;
char arr[51][51];
int visited[51][51], points[51][51], dist[260][260], p[260];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isInside(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	return p1.second < p2.second;
}

int distance_bfs(pair<int, int> start)
{
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = 0;
	int cnt = 0;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		if (points[x][y] != 0)
		{
			dist[points[start.first][start.second]][points[x][y]] = visited[x][y];
			cnt++;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (isInside(nx, ny) && visited[nx][ny] == -1 && arr[nx][ny] != '1')
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return cnt;
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

	if (a < b)
		p[b] = a;
	else p[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n >> k;

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 'S' || arr[i][j] == 'K')
				points[i][j] = ++cnt;
		}
	}

	bool checked = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 'S' || arr[i][j] == 'K')
			{
				memset(visited, 0xff, sizeof(visited));
				if (!checked)
				{
					int tmp = distance_bfs({ i, j });
					if (tmp != cnt)
					{
						cout << "-1" << endl;
						return 0;
					}
					checked = true;
				}
				
				else distance_bfs({ i, j });
			}
		}
	}

	vector<pair<pair<int, int>, int>> edges;

	for (int i = 1; i <= cnt; i++)
		for (int j = i + 1; j <= cnt; j++)
			if (dist[i][j] != 0)
				edges.push_back({ {i, j}, dist[i][j] });
	
	sort(edges.begin(), edges.end(), cmp);

	for (int i = 1; i <= cnt; i++) // parent 배열 초기화
		p[i] = i;

	int ans = 0;
	for (auto edge : edges)
	{
		if (find_parent(edge.first.first) == find_parent(edge.first.second))
			continue;

		union_parent(edge.first.first, edge.first.second);
		ans += edge.second;
	}

	cout << ans << endl;
	
	return 0;
}
