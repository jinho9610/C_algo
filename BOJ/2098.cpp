#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

const int INF = 1e9;
// ��� �� ���, dp[i][j]���� i��° ��忡��, ��ü������ �湮���� j�� �ǹ�
int n, w[24][24], dp[24][1 << 24]; 

void make_tsp_map(int citynum) // w �迭 �ʱ�ȭ�ϴ� �Լ�
{
	for (int i = 0; i < citynum; i++)
		for (int j = 0; j < citynum; j++)
			w[i][j] = min(abs(i - j), citynum - abs(i - j));
}

int tsp(int cur, int state)
{
	if ((state & 1) == 1 && state != (1 << n) - 1) // Ž���� ���������� ������(0��°) ��Ʈ�� 1�� �Ǵ� ���
		return INF;
	if (state == (1 << n) - 1) // Ž���� �������� // �� ���� ���� ��Ʈ�� �����Ͽ� ��� 1�� �� ���
		return 0; // v1 -> v1�� ����� 0�̹Ƿ� 0 ��ȯ

	int& ret = dp[cur][state]; // ���� min ���� �����ϱ� �����ϵ��� �ּҰ� ������
	if (ret != -1) // �̹� ���������κ����� �ּ� ����� ���� ����� ���
		return ret;

	ret = INF; // ���� min �����ϱ⿡ �����ϵ��� ū ������ ����
	for (int i = 0; i < n; i++)
	{
		// ������ �ְ�, ���� state �߿��� ��Ʈ�� 0�� ��쿡 ���ؼ��� Ž�� ����
		if (w[cur][i] > 0 && (state & (1 << i)) == 0)
		{
			// �������� i��带 �湮�ϴ� ���̹Ƿ� i��° ��Ʈ�� 1�� �����, cur -> i���� ��� �߰�
			ret = min(ret, tsp(i, state | (1 << i)) + w[cur][i]); // ���� ���� ret���� dp�� ����
		}
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	//cin >> n;
	//for (int i = 0; i < n; i++)
	//	for (int j = 0; j < n; j++)
	//		cin >> w[i][j];

	while (true)
	{
		cout << endl;
		memset(dp, 0xff, sizeof(dp)); // dp �迭 ��� -1�� �ʱ�ȭ
		cout << "���� ����: ";
		cin >> n;
		make_tsp_map(n); // w �迭 ����

		cout << "==========w �迭==========" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << w[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';

		memset(dp, 0xff, sizeof(dp)); // dp �迭 ��� -1�� �ʱ�ȭ

		clock_t start = clock();
		cout << "ã�� �ּ� ��� ���: " << tsp(0, 0) << endl;
		clock_t end = clock();
		cout << "�ҿ�ð�: " << (double)(end - start) << "ms" << endl;
		cout << "\n������Ű��а� 12161719 ����ȣ" << endl;
	}

	return 0;
}