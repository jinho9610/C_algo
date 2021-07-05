/* BOJ 1654 랜선 자르기 */
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

int k, n, arr[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> k >> n;
	for (int i = 1; i <= k; i++)
		cin >> arr[i];

	ll left = 1, right = *max_element(arr + 1, arr + 1 + k);
	int ans = 0;

	while (left <= right)
	{
		ll mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 1; i <= k; i++)
			cnt += (arr[i] / mid);

		if (cnt < n) // 조금더 잘게 잘라야함
			right = mid - 1;
		else ans = mid, left = mid + 1; // 조금 더 길게 잘라봐도 무방함
	}

	cout << ans << endl;

	return 0;
}