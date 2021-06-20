/**/
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

const int INF = 1e9;
int n, w[10][10], dp[10][1 << 10];

int tsp(int cur, int state)
{
	if (state & 1 && state != (1 << n) - 1)
		return INF;
	if (state & 1 && state == (1 << n) - 1)
		return 0;

	int& ret = dp[cur][state];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = 0; i < n; i++)
		if (w[cur][i] > 0 && !(state & (1 << i)))
			ret = min(ret, tsp(i, state | (1 << i)) + w[cur][i]);
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j]; // i -> j ºñ¿ë

	memset(dp, 0xff, sizeof(dp));

	cout << tsp(0, 0) << endl;

	return 0;
}
