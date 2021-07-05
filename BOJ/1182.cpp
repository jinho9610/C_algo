/* BOJ 1182 �κм����� �� */
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
	// idx�� �� �Լ��� ȣ��Ǳ� ������ arr[idx]�� �κ� ������ ���Ե����� �ǹ�
	// cnt�� ���� �κ� ������ ���Ե� ������ ���� �ǹ�
	// sum�� �κ� ������ �����ϴ� ��� ������ ���� �ǹ�
	// �κ� ������ �����ϴ� ���Ұ� 1�� �̻��̰�,
	// ��� ������ ���� s�� ���ٸ� ans 1 ����
	if (cnt > 0 && sum == s) 
		ans++;

	if (idx == n)
		return; // n�� �̻� ���� �Ұ�

	for (int i = idx + 1; i <= n; i++)
		dfs(i, cnt + 1, sum + arr[i]); // arr[i]�� �κ� ������ ���Խ�Ŵ
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
