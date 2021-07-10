/* BOJ 12865 평범한 배낭 */
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

int n, k, dp[101][100001];
pair<int, int> arr[101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) // 물건들의 무게와 가치 입력
		cin >> arr[i].first >> arr[i].second;

	for (int i = 1; i <= n; i++)
	{
		for (int w = 1; w <= k; w++)
		{
			if (arr[i].first > w)
				dp[i][w] = dp[i - 1][w];
			else
				dp[i][w] = max(dp[i - 1][w - arr[i].first] + arr[i].second, dp[i - 1][w]);
		}
	}

	cout << dp[n][k] << endl;

	return 0;
}
