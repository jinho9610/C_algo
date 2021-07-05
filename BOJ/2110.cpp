/* BOJ 2110 공유기 설치 */
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

int n, c, arr[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	int tmp_max = 0;

	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		tmp_max = max(tmp_max, arr[i]);
	}

	sort(arr + 1, arr + 1 + n);

	unsigned int left = 1, right = tmp_max;
	int ans = 0;

	while (left <= right)
	{
		unsigned int mid = (left + right) / 2;

		int cnt = 1;
		int prev_house = arr[1];

		for (int i = 2; i <= n; i++)
		{
			// 공유기가 설치된 이전 집과 mid 이상 떨어진 경우에만 설치
			if (arr[i] - prev_house >= mid)
			{
				cnt++; // 설치
				prev_house = arr[i];
			}
		}

		if (cnt >= c) // 좀 더 공유기 설치 간격을 넓혀도 무방함
		{
			ans = max(ans, (int)mid);
			left = mid + 1;
		}
		else // 좀 더 촘촘히 공유기 설치해야함
			right = mid - 1;
	}

	cout << ans << endl;

	return 0;
}
