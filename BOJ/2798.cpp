/* BOJ 2798 ∫Ì∑¢¿Ë*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

typedef long long ll;

int n, m, arr[101];
int ans = 0;

void dfs(int idx, int cnt, int sum)
{
	if (sum > m)
		return;

	if (cnt == 3)
	{
		ans = max(ans, sum);
		return;
	}

	for (int i = idx + 1; i <= n; i++)
	{
		dfs(i, cnt + 1, sum + arr[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	sort(arr + 1, arr + n + 1);

	dfs(0, 0, 0);

	cout << ans << endl;
	
	return 0;
}