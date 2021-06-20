/* BOJ 19645 햄최몇 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>

#define endl '\n'

using namespace std;

typedef long long ll;

int n, arr[51];
bool dp[2501][2501];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	int sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	// dp[x][y] : 첫째가 효용 x만큼 햄버거 먹고,
	// 둘째가 효용 y만큼 먹는 경우가 가능하면 1, 불가능하면 0
	dp[0][0] = true;
	for (int k = 0; k < n; k++)
	{
		for (int i = sum; i >= 0; i--)
		{
			for (int j = sum; j >= 0; j--)
			{
				if (i - arr[k] >= 0)
					dp[i][j] |= dp[i - arr[k]][j];
				if (j - arr[k] >= 0)
					dp[i][j] |= dp[i][j - arr[k]];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= sum; i++)
		for (int j = 0; j <= i; j++) // i가 첫째, j가 둘째이므로 j의 최대값은 i 이하
			if (dp[i][j] == true && j >= (sum - i - j)) // 막내는 sum - i - j이며, 이는 j 이하여야 한다
				ans = max(ans, sum - i - j);

	cout << ans << endl;

	return 0;
}
