#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int n, m, h, ans = 1e9;
bool arr[32][12];
bool found = false;

bool laddering()
{
	bool flag = true;
	for (int j = 1; j <= n; j++)
	{
		int cur = j;
		for (int i = 1; i <= h; i++)
		{
			if (cur == 1)
			{
				if (arr[i][cur])
					cur++;
			}

			else if (cur == n)
			{
				if (arr[i][cur - 1])
					cur--;
			}

			else
			{
				if (arr[i][cur])
					cur++;
				else if (arr[i][cur - 1])
					cur--;
			}
		}
		//cout << j << "는 " << cur << "에 도착했음" << endl;
		if (cur == j)
			continue;
		else
		{
			flag = false;
			break;
		}
	}
	return flag;
}

vector<pair<int, int>> pts;
void dfs(int idx, int cnt)
{
	if (cnt > 3)
		return;

	if (laddering())
	{
		ans = min(ans, cnt);
		return;
	}


	for (int i = idx; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (arr[i][j - 1] == false && arr[i][j] == false && arr[i][j + 1] == false)
			{
				//cout << i << ' ' << j << "에 설치" << endl;
				arr[i][j] = true;
				dfs(i, cnt + 1);
				arr[i][j] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("s_input.txt", "r", stdin);

	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = true;
	}
	
	dfs(1, 0);

	if (ans == 1e9)
		cout << -1 << endl;
	else
		cout << ans << endl;

	/*for (int i = 0; i <= 3; i++)
	{
		dfs(1, 0, i);
		if (found)
			break;
	}
	
	if (!found)
		cout << -1 << endl;
	else
		cout << ans << endl;*/

	return 0;
}