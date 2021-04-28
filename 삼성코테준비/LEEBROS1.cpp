#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;

int n, arr[21][21], visited[21][21];
int start_x, start_y, end_x, end_y, result = 1e9;
pii coin[10]; // coins[i]는 동전 i의 좌표 정보 저장
vector<int> coins;
vector<int> picked;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool isInside(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int bfs(pii p1, pii p2)
{
	memset(visited, 0xff, sizeof(visited));

	queue<pii> q;
	int sx = p1.first, sy = p1.second;
	int dex = p2.first, dey = p2.second;
	//(sx, sy)에서 (dex, dey)로 가는 최단 거리를 구할 것

	visited[sx][sy] = 0;
	q.push({ sx, sy });

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (x == dex && y == dey)
			return visited[x][y]; // 이상적인 중단점

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			// 맵 안이고, 방문한적 없고, 벽이 아니라면 전진
			if (isInside(nx, ny) && visited[nx][ny] == -1 && arr[nx][ny] != -1)
			{
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	// 이상적인 중단점에서 끝나지 않았다면
	return -1; // p1에서 p2로 가는 것은 불가능하다는 의미로 -1 반환
}

void dfs(int x, int y, int idx, int coin_cnt, int len)
{
	// len은 현재 이동 거리를 의미
	if (coin_cnt == 3)
	{
		//cantFind = false;
		int dist = bfs({ x, y }, { end_x, end_y });
		if (dist == -1)
			return;

		//cantFind = true;
		result = min(result, len + dist);
		/*for (auto p : picked)
			cout << p << ' ';
		cout << endl;*/
		return;
	}

	for (int i = idx + 1; i < coins.size(); i++)
	{
		// 현재 위치로부터 저 동전을 줍기 위해 이동해야하는 거리
		int dist = bfs({ x, y }, coin[coins[i]]);
		if (dist == -1) // 못 줍는데
			continue;

		//picked.push_back(coins[i]);
		dfs(coin[coins[i]].first, coin[coins[i]].second, i, coin_cnt + 1, len + dist); // 다른 동전도 주우러 가고
		//picked.pop_back();

	}
}

void print_arr()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	freopen("s_input.txt", "r", stdin);

	cin >> n;

	coins.push_back(-11); // dummy 값 하나 푸쉬
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c;
			cin >> c;

			if (c == '.')
				arr[i][j] = 0;
			else if (c == 'S')
			{
				arr[i][j] = 100; // 100은 시작지점 의{미
				start_x = i, start_y = j;
			}
			else if (c == 'E')
			{
				arr[i][j] = 101; //101은 종료지점
				end_x = i, end_y = j;
			}
			else if (c == '#')
				arr[i][j] = -1; // -1은 벽
			else
			{
				arr[i][j] = c - '0';
				coin[arr[i][j]] = { i, j };
				coins.push_back(arr[i][j]);
			}
		}
	}
	sort(coins.begin(), coins.end()); // 동전을 오름차순으로 정렬

	int dist = bfs({ start_x, start_y }, { end_x, end_y });
	if (dist == -1)
	{
		cout << -1 << endl;
		return 0;
	}

	dfs(start_x, start_y, 0, 0, 0);

	if (result == 1e9) // 제대로된 정답 못찾아서 result의 갱신이 없다면
		cout << -1 << endl; // -1출력
	else cout << result << endl;

	return 0;
}