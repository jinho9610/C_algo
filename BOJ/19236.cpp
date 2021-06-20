#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;
typedef long long ll;

struct FISH
{
	int x, y, dir;
	bool isAlive;
	
	void print()
	{
		if(isAlive)
			cout << "x: " << this->x << "  y: " << this->y << "  방향: " << dir << "   살아있음" << endl;
		else
			cout << "x: " << this->x << "  y: " << this->y << "  방향: " << dir << "   죽었음" << endl;
	}
};

struct SHARK
{
	int x, y, dir;
};

FISH fishes[17], tmp_fishes[17];
int arr[4][4], tmp_arr[4][4], result = 0;
SHARK shark;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };

bool isInside(int x, int y)
{
	return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void backup(int arr1[][4], FISH arr2[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			arr1[i][j] = arr[i][j];
	}
	for (int i = 1; i <= 16; i++)
	{
		arr2[i] = fishes[i];
	}
}

void load(int arr1[][4], FISH arr2[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			arr[i][j] = arr1[i][j];
	}
	for (int i = 1; i <= 16; i++)
	{
		fishes[i] = arr2[i];
	}
}

void status_changer(int sx, int sy, int fx, int fy, int fish_num, bool flag)
{
	//fish_num  - 기존에 물고기가 있던 위치
	// flag가 true이면 먹히는 상황임
	if (flag)
	{
		arr[sx][sy] = 0;
		arr[fx][fy] = -1;
		fishes[fish_num].isAlive = false;
	}
	else // 먹었던것 뱉어
	{
		arr[sx][sy] = -1;
		arr[fx][fy] = fish_num;
		fishes[fish_num].isAlive = true;
	}
}

void swap_fish(int fx1, int fy1, int fx2, int fy2)
{
	int f1 = arr[fx1][fy1];
	int f2 = arr[fx2][fy2];

	// 일단 arr 배열에서 물고기 번호 바꿔주고
	int tmp = arr[fx1][fy1];
	arr[fx1][fy1] = arr[fx2][fy2];
	arr[fx2][fy2] = tmp;

	fishes[f1].x = fx2, fishes[f1].y = fy2;
	fishes[f2].x = fx1, fishes[f2].y = fy1;

}

void fish_move()
{
	for (int i = 1; i <= 16; i++) // 1번 물고기부터 움직인다
	{
		// 이미 죽은 물고기라면 신경쓰지 x
		if (fishes[i].isAlive == false)
			continue;

		int fx = fishes[i].x, fy = fishes[i].y; // 현재 물고기 위치

		for (int k = 0; k < 8; k++)
		{
			// 현재 물고기 진행 방향은 fishes[i].dir
			// 물고기가 현재 진행 방향을 바탕으로 한 칸 전진할 경우의 좌표
			int nfx = fx + dx[fishes[i].dir], nfy = fy + dy[fishes[i].dir]; 

			if (isInside(nfx, nfy) && arr[nfx][nfy] != -1)
			{
				// 빈칸인 경우
				if (arr[nfx][nfy] == 0)
				{
					fishes[i].x = nfx, fishes[i].y = nfy; // 물고기 위치 단순 변경
					arr[nfx][nfy] = i;
					arr[fx][fy] = 0;
				}
				// 살아있는 물고기 존재하는 경우 exchange
				else if (arr[nfx][nfy] > 0 && fishes[arr[nfx][nfy]].isAlive)
				{
					swap_fish(fx, fy, nfx, nfy);
				}
				break;
			}
			else
				fishes[i].dir = (fishes[i].dir + 1) % 8; // 45도 반시계 방향 회전
		}
	}
}

void print_arr()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << arr[i][j] << ' ';

		cout << "\t\t";
		for (int j = 0; j < 4; j++)
			cout << fishes[arr[i][j]].dir << ' ';

		cout << endl;
	}
}

void dfs(int sx, int sy, int s_dir, int sum)
{
	int tmp[4][4];
	FISH tmp_fishes[17];
	//cout << sx << ' ' << sy << endl;
	backup(tmp, tmp_fishes);

	// sum은 지금까지 먹은 물고기 번호의 합
	result = max(result, sum);
	

	// 물고기 움직인다
	fish_move();
	//print_arr();

	for (int i = 1; i <= 3; i++)
	{
		//cout << s_dir << endl;
		int fx = sx + i * dx[s_dir], fy = sy + i * dy[s_dir]; // 현재 바라보는 방향에서 먹을 수 있는 물고기의 위치
		int fish_num = arr[fx][fy];
		
		int fish_dir = fishes[fish_num].dir;

		if (fish_num == 0)
			continue;

		if (!isInside(fx, fy)) // 공간 밖의 영역이거나 이라면 먹을 수 없다.
			continue;
		
		if (fishes[fish_num].isAlive == false) // 죽은 물고기라면 먹을 수 없다
			continue;

		status_changer(sx, sy, fx, fy, fish_num, true); // 먹는다
		//cout << i << "번째 for문이고 " << fx << ", " << fy << " 에 있는 " << fish_num << " 먹었다." << endl;
		dfs(fx, fy, fish_dir, sum + fish_num); // 다음 물고기 먹는다
		status_changer(sx, sy, fx, fy, fish_num, false); // 뱉는다
		//cout << i << "번째 for문이고 " << fx << ", " << fy << " 에 있는 " << fish_num << " 뱉었다." << endl;

		//cout << endl;
	}

	load(tmp, tmp_fishes);
	//cout << "=================================" << endl;
}

int main()
{
	freopen("s_input.txt", "r", stdin);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int fish_num, dir;
			cin >> fish_num >> dir;
			arr[i][j] = fish_num;
			fishes[fish_num] = { i,j, dir - 1, true };
		}
	}

	int start_num = arr[0][0];
	int shark_dir = fishes[start_num].dir;
	
	fishes[start_num].isAlive = false; // (0, 0)에 있던 물고기 죽음
	arr[0][0] = -1; // (0, 0)에 상어 위치함

	dfs(0, 0, shark_dir, start_num);

	cout << result << endl;

	return 0;
}