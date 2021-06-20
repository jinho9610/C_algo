#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;

int T, n, m, result = 0;
bool arr[21][21];
int visited[21][21];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool isInside(int x, int y)
{
	return 1 <= x && 1 <= n && 1 <= y && y <= n;
}

void print_arr()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j])
				cout << 'O' << ' ';
			else
				cout << 'X' << ' ';
		}
		cout << endl;
	}
}

int bfs(pii p, int limit)
{
	queue<pii> q;
	visited[p.first][p.second] = 0;
	int cnt = 0;
	q.push(p);

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (visited[x][y] <= limit && arr[x][y])
			cnt++;
		if(visited[x][y] >limit)
			break;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (isInside(nx, ny) && visited[nx][ny] == -1)
			{
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	return cnt;
}

int main()
{
	freopen("s_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		memset(arr, 0x00, sizeof(arr));

		cin >> n >> m;

		int cnt = 0; // 가구 수
		result = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j])
					cnt++;
			}
		}
		//cout << "테스트케이스 " << t << "   " << cnt << endl;
		int k = 1;
		while (true)
		{
			int cost = k * k + (k - 1) * (k - 1);
			if (cost > m * cnt)
				break;

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					memset(visited, 0xff, sizeof(visited));
					int tmp = bfs({ i, j }, (k - 1));
					//if(t==1) cout <<cost<<" "<< tmp << endl;
					if(cost <= m * tmp)
						result = max(result,tmp);
				}
			}
			k++;
		}

		cout << "#" << t << " " << result << endl;
	}


	return 0;
}