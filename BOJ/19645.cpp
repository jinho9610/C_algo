/* BOJ 19645 ���ָ� */
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

int n, arr[51];
bool dp[2501][2501];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	int sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	// dp[x][y] : ù°�� ȿ�� x��ŭ �ܹ��� �԰�,
	// ��°�� ȿ�� y��ŭ �Դ� ��찡 �����ϸ� 1, �Ұ����ϸ� 0
	dp[0][0] = true;
	for (int k = 0; k < n; k++)
	{
		for (int i = sum; i >= 0; i--)
		{
			for (int j = sum; j >= 0; j--)
			{
				if (i - arr[k] >= 0)
					dp[i][j] |= dp[i - arr[k]][j];
				if (j - arr[k] >= 0)
					dp[i][j] |= dp[i][j - arr[k]];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= sum; i++)
		for (int j = 0; j <= i; j++) // i�� ù°, j�� ��°�̹Ƿ� j�� �ִ밪�� i ����
			if (dp[i][j] == true && j >= (sum - i - j)) // ������ sum - i - j�̸�, �̴� j ���Ͽ��� �Ѵ�
				ans = max(ans, sum - i - j);

	cout << ans << endl;

	return 0;
}
