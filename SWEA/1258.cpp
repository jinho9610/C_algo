/* SWEA 1258 행렬찾기 */
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

int t, T, n, arr[101][101];
bool visited[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool isInside(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

pair<int, int> bfs(pair<int, int> start)
{
	int max_height = 0, max_width = 0;

	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		max_height = max(max_height, abs(x - start.first) + 1);
		max_width = max(max_width, abs(y - start.second) + 1);

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (isInside(nx, ny) && arr[nx][ny] > 0 && !visited[nx][ny])
			{
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
	return {max_height, max_width};
}

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	int p1_size = p1.first * p1.second;
	int p2_size = p2.first * p2.second;
	
	if (p1_size != p2_size)
		return p1_size < p2_size;
	else
		return p1.first < p2.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		memset(visited, 0x00, sizeof(visited));

		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];

		int cnt = 0;
		vector<pair<int, int>> submatrix;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!visited[i][j] && arr[i][j] > 0)
				{
					cnt++; // 서브행렬의 개수
					pair<int, int> length_info = bfs({ i,j });
					submatrix.push_back({ length_info });
				}
			}
		}

		sort(submatrix.begin(), submatrix.end(), cmp);

		cout << "#" << t << ' ' << cnt << ' ';
		for (auto sub : submatrix)
			cout << sub.first << ' ' << sub.second << ' ';
		cout << endl;
	}

	return 0;
}
