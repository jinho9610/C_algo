#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct PEDES
{
	int x, y;
	bool isPedes;
};

#define endl '\n'
typedef pair<int, int> pii;

int n, m, fuel;
int arr[21][21]; // arr[x][y] == 1 -> (x, y)는 벽이다.
int visited[21][21];
int tx, ty;
bool cantFind = false;
bool cantGo = true;
PEDES pedes[21][21];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool isInside(int x, int y)
{
	return 1 <= x && x <= n and 1 <= y && y <= n;
}

bool cmp(pii p1, pii p2)
{
	if (p1.first < p2.first)
		return true;
	else if (p1.first == p2.first)
	{
		if (p1.second < p2.second)
			return true;
		else return false;
	}
	else return false;
}

pair<pii, int> pick_rider()
{
	cantFind = false;
	vector<pii> candi;
	memset(visited, 0xff, sizeof(visited));

	// 현재 택시 위치에서 가장 가까운 승객 골라낸다.
	queue<pii> q;
	visited[tx][ty] = 0;
	q.push({ tx, ty });

	bool found = false;
	int min_dist;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (!found && pedes[x][y].isPedes == true)
		{
			min_dist = visited[x][y];
			found = true;
		}
		if (found && visited[x][y] == min_dist && pedes[x][y].isPedes == true) // 승객이라면
			candi.push_back({ x, y });
		if (found && visited[x][y] > min_dist)
			break;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (isInside(nx, ny) && visited[nx][ny] == -1 && arr[nx][ny] != 1)
			{
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	if (candi.size() == 0) // 승객 후보가 아무도 없는 경우
	{
		cantFind = true;
		return { {500, 500}, 500 };  // dummy 값
	}
	else
	{
		sort(candi.begin(), candi.end(), cmp);
		return { candi[0], min_dist };
	}
}

int navigate(pii dest)
{
	memset(visited, 0xff, sizeof(visited));
	cantGo = true;
	int min_dist;
	queue<pii> q;
	q.push({ tx, ty });
	visited[tx][ty] = 0;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;

		q.pop();
		if (x == dest.first && y == dest.second)
		{
			min_dist = visited[x][y];
			cantGo = false;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (isInside(nx, ny) && visited[nx][ny] == -1 && arr[nx][ny] != 1)
			{

				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	if (cantGo)
		return 1000;
	else
		return min_dist;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("s_input.txt", "r", stdin);

	cin >> n >> m >> fuel;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	cin >> tx >> ty; // 택시 시작지점

	for (int i = 1; i <= m; i++)
	{
		int sx, sy, ex, ey;

		cin >> sx >> sy >> ex >> ey;

		pedes[sx][sy] = { ex, ey, true }; // (sx, sy)에 있는 승객은 {ex, ey}로 가기를 원한다.
	}

	while (m--)
	{
		// 가장 가까운 승객이 있는 골라낸다.
		pair<pii, int> rider_info = pick_rider();
		if (cantFind == true)
		{
			cout << -1 << endl;
			return 0;
		}

		int rx = rider_info.first.first, ry = rider_info.first.second; // 승객 위치
		int dist = rider_info.second; // 현재 택시로부터 승객까지의 거리

		// 태울 수 있는 지 연료양 체크
		if (fuel <= dist)
		{
			cout << -1 << endl;
			return 0;
		}

		int dex, dey; // 승객의 목표 도착지
		if (pedes[rx][ry].isPedes) // 승객인지 한번 더 체크하고
			dex = pedes[rx][ry].x, dey = pedes[rx][ry].y;

		tx = rx, ty = ry; // 택시 이동
		fuel -= dist; // 승객 위치까지 이동한 후 연료량

		// 도착가능한 지 체크
		int dist_to_dest = navigate({ dex, dey });

		if (cantGo == true) // 불가능하다면
		{
			cout << -1 << endl;
			return 0;
		}

		if (fuel < dist_to_dest)
		{
			cout << -1 << endl;
			return 0;
		}

		// 택시를 승객의 도착지로 이동한 후 연료 소모 및 충전
		tx = dex, ty = dey;
		fuel = fuel + dist_to_dest;

		// 승객 제거
		pedes[rx][ry].isPedes = false;

	}

	cout << fuel << endl;

	return 0;
}