/* BOJ 1789 수들의 합 */
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

ll s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> s;

	ll left = 1, right = s;
	ll ans = 0, mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if ((mid * (mid + 1)) / 2 > s)
			right = mid - 1;
		else
		{
			left = mid + 1;
			ans = mid;
		}
	}

	cout << ans << endl;

	return 0;
}
