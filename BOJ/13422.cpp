/* BOJ 13422 ���� */
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
			// �迭�� ���۰� ���� ����� �����̹Ƿ�
			// �迭�� �ι�� Ȯ���Ͽ� �������� �ι� �ݺ�
			arr[i] = a, arr[i + n] = a;
		}

		if (n == m)
		{
			// n == m�̸� ������ ������ ��찡 �ݺ��ǹǷ� �ѹ��� Ȯ��
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
