/* SWEA 1244 �ִ� ��� */
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

int t, T, swap_cnt, ans = 0;
string num;
bool visited[1000000][11];
// visited[a][b] - �������� b�� ���� �� a��� ���� �̹� �����߾��� �� Ȯ���ϱ� ���� �迭

void dfs(int cnt)
{
	if (cnt == swap_cnt) // �ִ� ������ Ƚ����ŭ ������ ����������
	{
		ans = max(ans, stoi(num)); // �� ū ������ ����
		return; // �ǵ��ư��� ���� Ž�� ��� ����
	}

	for (int i = 0; i < num.length() - 1; i++)
	{
		for (int j = i + 1; j < num.length(); j++)
		{
			swap(num[i], num[j]); // i��° ���� j��° �� �ٲ�ġ��(�� �� ������ Ƚ���� cnt + 1)�� ��
			if (!visited[stoi(num)][cnt + 1]) // �ش� Ƚ����ŭ ���������� �� ������ ���� ���� �����
			{
				visited[stoi(num)][cnt + 1] = true; // ���� ������ ������ üũ���ְ�
				dfs(cnt + 1); // ���� Ž�� ����ؼ� ����
			}
			swap(num[i], num[j]); // �ٲ�ġ�� �ߴ� ���� ���� �ڸ��� �ǵ���
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		ans = 0; // �ʱ�ȭ
		memset(visited, 0x00, sizeof(visited)); // �ʱ�ȭ

		cin >> num >> swap_cnt;

		// ���� Ž�� ����
		dfs(0);

		cout << "#" << t << ' ' << ans << endl;
	}

	return 0;
}
