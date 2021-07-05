/* BOJ 1182 부분수열의 합 */
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

int n, s, arr[21], ans;

void dfs(int idx, int cnt, int sum)
{
	// idx는 이 함수가 호출되기 직전에 arr[idx]가 부분 수열에 포함됐음을 의미
	// cnt는 현재 부분 수열에 포함된 원소의 수를 의미
	// sum은 부분 수열을 구성하는 모든 원소의 합을 의미
	// 부분 수열을 구성하는 원소가 1개 이상이고,
	// 모든 원소의 합이 s와 같다면 ans 1 증가
	if (cnt > 0 && sum == s) 
		ans++;

	if (idx == n)
		return; // n개 이상 선택 불가

	for (int i = idx + 1; i <= n; i++)
		dfs(i, cnt + 1, sum + arr[i]); // arr[i]를 부분 수열에 포함시킴
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dfs(0, 0, 0);

	cout << ans << endl;

	return 0;
}
