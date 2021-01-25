#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int r, c;
char arr[51][51];
bool visited[51][51];
int dest_x, dest_y;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 }; // 물과 고슴도치의 상하좌우 이동을 위한 증분

queue<pair<int, int>> water;
queue<pair<int, int>> start;

int bfs()
{
	int cnt = 0;
	while (!start.empty())
	{
		cnt++;
		int water_size = water.size();
		while (water_size--) // 새로 추가된(while문을 돌며 퍼져나가는) 물 말고, 기존의 물들에 대해서만 퍼져나감 고려
		{
			//먼저 물이 퍼져나가는 것부터 고려
			int x = water.front().first;
			int y = water.front().second; // 물이 위치한 좌표
			water.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // 맵밖으로 벗어나면 무시하기
				if (arr[nx][ny] == 'X' || arr[nx][ny] == 'D' || arr[nx][ny] == '*') continue;
				
				water.push(make_pair(nx, ny));
				arr[nx][ny] = '*'; // 물이 퍼져나간 것으로 업데이트 
			}
		}

		int start_size = start.size();
		while (start_size--)
		{
			int x = start.front().first;
			int y = start.front().second;
			start.pop();

			visited[x][y] = true;
			if (x == dest_x && y == dest_y)
			{
				cout << cnt - 1 << endl;
				return 0;
			}

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // 맵을 벗어난다면 무시
				if (arr[nx][ny] == 'X' || arr[nx][ny] == '*' || visited[nx][ny]) continue; // 돌이나 물이 있는 곳 또는 이미 방문한 곳도 무시

				start.push(make_pair(nx, ny)); // 방문
				visited[nx][ny] = true; // 방문처리
			}
		}
	}
	cout << "KAKTUS" << endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				start.push(make_pair(i, j));
			}
			else if (arr[i][j] == 'D')
			{
				dest_x = i;
				dest_y = j;
			}
			else if (arr[i][j] == '*')
			{
				water.push(make_pair(i, j));
			}
		}
	}

	bfs();

	return 0;
}