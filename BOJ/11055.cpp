/* BOJ 11055 ���� ū ���� �κ� ���� */
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

int n, arr[1001], dp[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	// dp[i]��, i��° ������ ���Ҵ� �����ϰ�
	// i��° ���Ҹ� �������� �� ������ �� �ִ� �κ� ���� ���� ��
	// �� ���� �ִ븦 �ǹ���
	// �ܼ��� �־��� ���� A���� i��° ���ұ�����
	// ������ �̿��ϴ� ��츦 �ǹ��ϴ� ���� �ƴ϶�
	// �κ� ���� ������ ���ҿ� i��° ���Ұ� ���ԵǴ� ��츦 �ǹ�!
	dp[1] = arr[1];
	int ans = dp[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = arr[i]; // �ϴ� �ڱ� �ڽ����� �ʱ�ȭ
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
		ans = max(ans, dp[i]); // �κ� ���� ������ ������ �� �� �ִ밪 ã��
	}

	cout << ans << endl;

	return 0;
}
