/* SWEA 12052 부서진 타일 */
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

int t, T, n, m;
char arr[51][51];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		cin >> n >> m;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '#')
					cnt++;
			}
		}

		if (cnt % 4 != 0)
		{
			cout << "#" << t << " NO" << endl;
			continue;
		}

		for (int i = 1; i <= n-1; i++)
		{
			for (int j = 1; j <= m-1; j++)
			{
				if (arr[i][j] == '#')
				{
					if (arr[i][j + 1] == '#' && arr[i + 1][j] == '#' && arr[i + 1][j + 1] == '#')
					{
						arr[i][j] = '.';
						arr[i + 1][j] = '.';
						arr[i][j + 1] = '.';
						arr[i + 1][j + 1] = '.';
					}
				}
			}
		}

		bool repaired = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (arr[i][j] == '#') // 아직 부셔진 타일이 남아있다면
					repaired = false;
			}
		}

		if (repaired)
			cout << "#" << t << " YES" << endl;
		else
			cout << "#" << t << " NO" << endl;
	}

	return 0;
}
