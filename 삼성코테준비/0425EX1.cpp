#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <algorithm>

#define endl '\n'

using namespace std;

int arr[51][51];
bool isCloud[51][51], tmp[51][51];
bool isRained[51][51];
int n, m;

int dx[] = { 0, 0, -1, -1, -1, 0, 1,1,1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void print_arr()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void print_cloud()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isCloud[i][j])
				cout << "C ";
			else
				cout << "X ";
		}
		cout << endl;
	}
	cout << endl;
}

void move_cloud(int d, int p)
{	
	memset(tmp, 0x00, sizeof(tmp));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isCloud[i][j] == false)
				continue;

			int nx = (n + i + (dx[d] * p) % n) % n, ny = (n + j + (dy[d] * p) % n) % n;

			tmp[nx][ny] = true;
			isCloud[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tmp[i][j] == true)
				isCloud[i][j] = tmp[i][j];
		}
	}
}

void rain_cloud()
{
	memset(isRained, 0x00, sizeof(isRained));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isCloud[i][j])
			{
				arr[i][j]++;
				isRained[i][j] = true;
				isCloud[i][j] = false;
			}
		}
	}
}

bool isInside(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

void water_check() // 대각 방향 고려하여 물 체크
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isRained[i][j] == false)
				continue;

			for (int k = 2; k <= 8; k += 2)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if (isInside(nx, ny) && arr[nx][ny] > 0)
				{
					arr[i][j]++;
				}
			}
		}
	}
}

void make_cloud()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isRained[i][j])
				continue;

			if (arr[i][j] >= 2)
			{
				arr[i][j] -= 2;
				isCloud[i][j] = true;
			}
		}
	}
}

int check()
{
	int tot = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] > 0)
				tot += arr[i][j];

	return tot;
}

int main()
{
	freopen("s_input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if ((i == n - 2 || i == n - 1) && (j==0 || j==1))
				isCloud[i][j] = true;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int d, p;
		cin >> d >> p;

		//print_cloud();

		// 영양제 움직이고
		move_cloud(d, p);
		//print_cloud();
		// 나무 기르고
		rain_cloud();

		// 대각선 방향 나무들 검사하고
		water_check();

		// 나무 자르고 영양제 추가
		make_cloud();
	}

	cout << check() << endl;


	return 0;
}