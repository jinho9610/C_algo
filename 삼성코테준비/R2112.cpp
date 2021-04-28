#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>

#define endl '\n'
#define A 0
#define B 1

using namespace std;

int T, d, w, k, arr[14][21];

//void backup(int tmp[][21])
//{
//	for (int i = 1; i <= d; i++)
//		for (int j = 1; j <= w; j++)
//			tmp[i][j] = arr[i][j];
//}

void backup(int row, int tmp[])
{
	for (int j = 1; j <= w; j++)
		tmp[j] = arr[row][j];
}

void load(int row, int tmp[])
{
	for (int j = 1; j <= w; j++)
		arr[row][j] = tmp[j];
}

void injection(int row, int type)
{
	for (int j = 1; j <= w; j++)
		arr[row][j] = type;
}

bool inspection()
{
	bool flag = true;
	for (int j = 1; j <= w; j++)
	{
		bool found = false;
		int cur = arr[1][j], cnt = 1;
		for (int i = 2; i <= d; i++)
		{
			if (cur != arr[i][j])
			{
				cur = arr[i][j];
				cnt = 1;
			}
			else if (arr[i][j] == cur)
				cnt++;

			if (cnt == k)
			{
				found = true;
				break;
			}
		}
		if (found == false)
		{
			flag = found;
			break;
		}
	}
	return flag;
}

void print_arr()
{
	for (int i = 1; i <= d; i++)
	{
		for (int j = 1; j <= w; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}

vector<int> rows;
int dfs(int row, int cnt)
{
	// 이번 row행에 약을 넣을 것이고, 현재까지는 cnt개 넣었음

	if (cnt > k)
		return k;

	if (row == d + 1)
	{
		if (inspection())
			return cnt;
		else
			return k;
	}

	int tmp[21], result = 1e9;

	backup(row, tmp);

	// 이번 행에 약을 넣지 않는 경우
	result = min(dfs(row + 1, cnt), result);

	injection(row, A);
	if (cnt + 1 < result)
		result = min(dfs(row + 1, cnt + 1), result);

	injection(row, B);
	if (cnt + 1 < result)
		result = min(dfs(row + 1, cnt + 1), result);

	load(row, tmp);

	return result;
}

int main()
{
	//freopen("s_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		// 초기화
		memset(arr, 0x00, sizeof(arr));

		cin >> d >> w >> k;

		for (int i = 1; i <= d; i++)
			for (int j = 1; j <= w; j++)
				cin >> arr[i][j];

		if (inspection())
		{
			cout << "#" << t << " " << 0 << endl;
			continue;
		}

		cout << "#" << t << " " << dfs(1, 0) << endl;
	}
	return 0;
}