/* BOJ 11055 가장 큰 증가 부분 수열 */
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

int n, arr[1001], dp[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	// dp[i]는, i번째 이후의 원소는 무시하고
	// i번째 원소를 포함했을 때 생성할 수 있는 부분 증가 수열 중
	// 그 합의 최대를 의미함
	// 단순히 주어진 수열 A에서 i번째 원소까지의
	// 수들을 이용하는 경우를 의미하는 것이 아니라
	// 부분 증가 수열의 원소에 i번째 원소가 포함되는 경우를 의미!
	dp[1] = arr[1];
	int ans = dp[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = arr[i]; // 일단 자기 자신으로 초기화
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
		ans = max(ans, dp[i]); // 부분 증가 수열의 원소의 합 중 최대값 찾기
	}

	cout << ans << endl;

	return 0;
}
