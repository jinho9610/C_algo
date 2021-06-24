/* BOJ 11722 가장 긴 감소하는 수열 */
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

int n, arr[1001], dp[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (arr[i] < arr[j]) // 감소하는 수열이 되기 위해 값 비교부터 진행
				dp[i] = max(dp[i], dp[j] + 1);

	cout << *max_element(dp + 1, dp + n + 1) << endl;

	return 0;
}
