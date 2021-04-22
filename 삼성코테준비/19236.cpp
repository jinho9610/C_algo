#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define endl '\n'

using namespace std;

struct FISH {
	int x, y, dir;
	bool isAlive;
};

int arr[5][5], tmp_arr[5][5], result;
FISH fishes[17], tmp_fishes[17];

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void backup()
{
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			tmp_arr[i][j] = arr[i][j];

	for (int i = 1; i <= 16; i++)
		tmp_fishes[i] = fishes[i];
}

void load_backup()
{
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			arr[i][j] = tmp_arr[i][j];

	for (int i = 1; i <= 16; i++)
		fishes[i] = tmp_fishes[i];
}

bool isInside(int x, int y)
{
	return 1 <= x && x <= 4 && 1 <= y && y <= 4;
}

void swap_fishes(int x, int y, int nx, int ny)
{
	int cur_fish = arr[x][y];
	int new_fish = arr[nx][ny];
	arr[x][y] = new_fish, arr[nx][ny] = cur_fish; // 물고기 번호 바꿔주고

	fishes[cur_fish].x = nx, fishes[cur_fish].y = ny;
	fishes[new_fish].x = x, fishes[new_fish].y = y;
}

void print_arr()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}

void Swap_Fish(int Idx, int IIdx)
{
	/* 물고기들 끼리 자리를 바꾸는 경우 물고기들의 좌표를 바꿔주는 함수. */
	FISH Temp = fishes[Idx];
	fishes[Idx].x = fishes[IIdx].x;
	fishes[Idx].y = fishes[IIdx].y;
	fishes[IIdx].x = Temp.x;
	fishes[IIdx].y = Temp.y;
}


void Move_Fish()
{
	/* 물고기의 움직임을 나타내는 함수. */
	for (int i = 1; i <= 16; i++)
	{
		if (fishes[i].isAlive == false) continue;

		int x = fishes[i].x;
		int y = fishes[i].y;
		int Dir = fishes[i].dir;

		int nx = x + dx[Dir];
		int ny = y + dy[Dir];
		bool Flag = false;
		if (nx >= 1 && ny >= 1 && nx <= 4 && ny <= 4)
		{
			if (arr[nx][ny] == 0)
			{
				Flag = true;
				fishes[i].x = nx;
				fishes[i].y = ny;
				arr[nx][ny] = i;
				arr[x][y] = 0;
			}
			else if (arr[nx][ny] != -1)
			{
				Flag = true;
				Swap_Fish(i, arr[nx][ny]);
				swap(arr[x][y], arr[nx][ny]);
			}
		}

		/* 여기까지 왔는데 Flag = false 라는 것은,
		 * 물고기가 현재 진행방향으로는 움직일 수 없다는 것을 의미. */
		 /* 다른 7방향을 탐색해본다. */
		if (Flag == false)
		{
			int nDir = Dir + 1;
			if (nDir == 9) nDir = 1;
			int nx = x + dx[nDir];
			int ny = y + dy[nDir];

			while (nDir != Dir)
			{
				if (nx >= 1 && ny >= 1 && nx <= 4 && ny <= 4)
				{
					if (arr[nx][ny] == 0)
					{
						fishes[i].x = nx;
						fishes[i].y = ny;
						arr[nx][ny] = i;
						arr[x][y] = 0;
						fishes[i].dir = nDir;
						break;
					}
					else if (arr[nx][ny] != -1)
					{
						Swap_Fish(i, arr[nx][ny]);
						swap(arr[x][y], arr[nx][ny]);
						fishes[i].dir = nDir;
						break;
					}
				}
				nDir++;
				if (nDir == 9) nDir = 1;
				nx = x + dx[nDir];
				ny = y + dy[nDir];
			}
		}
	}
}


void state_changer(int x, int y, int fx, int fy, int num, bool flag)
{
	if (flag == true) //(x,y)의 상어가 (fx, fy)의 물고기를 먹은 경우
	{
		arr[x][y] = 0;
		arr[fx][fy] = -1;
		fishes[num].isAlive = false; // 물고기 잡아먹힘 의미
	}
	else //(fx,fy)의 상어가 물고기를 뱉고 다시 (x, y)로 돌아가는 경우
	{
		arr[x][y] = -1;
		arr[fx][fy] = num;
		fishes[num].isAlive = true;
	}
}

void dfs(int x, int y, int dir, int tot)
{
	result = max(result, tot);

	//모든 상태 백업해두기
	backup();

	// 물고기 움직이기
	//fish_move();
	Move_Fish();

	// 상어 움직이기
	for (int i = 1; i <= 3; i++)
	{
		// 상어가 다음 움직일 곳
		int nx = x + i * dx[dir], ny = y + i * dy[dir];

		if (isInside(nx, ny))
		{
			if (arr[nx][ny] == 0) // 이미 먹혔다면 상어가 그곳으로 이동 불가
				continue;

			int fish_num = arr[nx][ny]; // 먹으려는 물고기의 번호
			int new_dir = fishes[fish_num].dir;

			// 상어와 물고기 상태 변화
			state_changer(x, y, nx, ny, fish_num, true); // true는 먹혔음을 의미
			dfs(nx, ny, new_dir, tot + fish_num);
			// 상어와 물고기 상태 변화 되돌리기
			state_changer(x, y, nx, ny, fish_num, false); // false는 먹은 것을 뱉고 뒤로 돌아가는 것을 의미
		}
	}

	//모든 상태 되돌리기
	load_backup();
}

int main()
{
	freopen("s_input.txt", "r", stdin);

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int a, b;
			cin >> a >> b;
			arr[i][j] = a;
			fishes[a] = { i, j, b, true };
		}
	}
	fishes[arr[1][1]].isAlive = false;
	int start_num = arr[1][1];
	arr[1][1] = -1;

	dfs(1, 1, fishes[start_num].dir, start_num);
	
	cout << result << endl;

	return 0;
}