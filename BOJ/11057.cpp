/* BOJ 11057 �������� */
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

// dp[i][j]�� ���̰� i�� �� �߿��� j�� ������ ������ ���� ������ �ǹ�
int n, dp[1001][10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1; // 0, 1, 2, 3, 4 ... 9 ��� �Ѱ��� ���

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			int cnt = 0;
			for (int k = 0; k <= j; k++)
			{
				cnt += (dp[i - 1][k] % 10007);
			}
			dp[i][j] = cnt % 10007;
		}
	}

	int ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += dp[n][i];
	cout << ans % 10007 << endl;

	return 0;
}
