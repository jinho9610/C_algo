/* BOJ 14499 주사위 굴리기 */
/* 구현, 시뮬레이션 */
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

int n, m, init_x, init_y, k;
vector<int> commands;
int arr[20][20];
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

typedef struct DICE
{
	int top, bot, right, left, front, back;
	int x, y;

	DICE()
	{
		top = 0, bot = 0, left = 0, front = 0, back = 0;
		x = init_x, y = init_y;
	}

} DICE;

bool isInside(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

void rotate_dice(DICE& dice, int com)
{
	if (com == 1) // 동쪽으로 굴리기
	{
		int tmp = dice.left;
		dice.left = dice.bot;
		dice.bot = dice.right;
		dice.right = dice.top;
		dice.top = tmp;
	}
	else if (com == 2) // 서쪽으록 굴리기
	{
		int tmp = dice.right;
		dice.right = dice.bot;
		dice.bot = dice.left;
		dice.left = dice.top;
		dice.top = tmp;
	}
	else if (com == 3) // 북쪽으로 굴리기
	{
		int tmp = dice.back;
		dice.back = dice.top;
		dice.top = dice.front;
		dice.front = dice.bot;
		dice.bot = tmp;
	}
	else // 남쪽으로 굴리기
	{
		int tmp = dice.front;
		dice.front = dice.top;
		dice.top = dice.back;
		dice.back = dice.bot;
		dice.bot = tmp;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n >> m >> init_x >> init_y >> k;
	for (int i = 0; i < n; i++) // 초기 보드 상태 입력
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	while (k--)
	{
		int a;
		cin >> a;
		commands.push_back(a);
	}

	DICE dice = DICE();
	for (int command : commands)
	{
		// 주사위가 이동할 칸의 좌표 구하기
		int nx = dice.x + dx[command], ny = dice.y + dy[command];

		if (!isInside(nx, ny)) // 주사위가 맵 밖으로 굴러가면
			continue; // 해당 명령 무시

		dice.x = nx, dice.y = ny; // 주사위 이동
		rotate_dice(dice, command);

		if (arr[dice.x][dice.y] == 0)
			arr[dice.x][dice.y] = dice.bot;
		else
		{
			dice.bot = arr[dice.x][dice.y];
			arr[dice.x][dice.y] = 0;
		}

		cout << dice.top << endl;
	}
	return 0;
}
