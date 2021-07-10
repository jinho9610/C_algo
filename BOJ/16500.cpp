/* BOJ 16500 문자열 판별 */
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

int n, dp[101];
string str, arr[101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> str >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[str.length()] = 1;
	for (int cur = str.length() - 1; cur >= 0; cur--)
	{
		for (int i = 1; i <= n; i++)
		{
			if (str.substr(cur, arr[i].length()) == arr[i])
			{
				if (dp[cur + arr[i].length()] == 1)
				{
					dp[cur] = 1;
					break;
				}
			}
		}
	}

	cout << dp[0] << endl;

	return 0;
}
