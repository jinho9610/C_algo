/* BOJ 11399 ATM */
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

int n, arr[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	sort(arr + 1, arr + 1 + n);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			ans += arr[j];

	cout << ans << endl;

	return 0;
}
