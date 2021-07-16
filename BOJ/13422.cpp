/* BOJ 13422 도둑 */
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

int t, T, n, m, k;
int arr[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		cin >> n >> m >> k;

		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			// 배열의 시작과 끝이 연결된 원소이므로
			// 배열을 두배로 확장하여 시퀀스를 두번 반복
			arr[i] = a, arr[i + n] = a;
		}

		if (n == m)
		{
			// n == m이면 완전히 동일한 경우가 반복되므로 한번만 확인
			int sum = 0;
			for (int i = 1; i <= n; i++)
				sum += arr[i];

			if (sum < k)
			{
				cout << 1 << endl;
				continue;
			}
		}

		int cnt = 0, sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
			{
				for (int j = 0; j < m; j++)
					sum += arr[i + j];
			}

			else
				sum = sum - arr[i - 1] + arr[i - 1 + m];

			if (sum < k)
				cnt++;
		}

		cout << cnt << endl;
	}

	return 0;
}
