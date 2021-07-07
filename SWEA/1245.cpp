/* swea 1245 ������ */
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

int t, T, n;
double x[11], m[11], ans[11];

double left_power(int p, double bp_x) // ���� �ڼ�ü�κ����� �η�
{
	double lp = 0.;
	// bp_x�� �������� x ��ǥ
	for (int i = 1; i <= p; i++)
	{
		double d = bp_x - x[i];
		lp += (m[i] / (d * d));
	}

	return lp;
}

double right_power(int p, double bp_x) // ������ �ڼ�ü�κ����� �η�
{
	double rp = 0.;
	// bp_x�� �������� x ��ǥ
	for (int i = p + 1; i <= n; i++)
	{
		double d = bp_x - x[i];
		rp += (m[i] / (d * d));
	}

	return rp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		cin >> n;
		// ��ǥ �Է�
		for (int i = 1; i <= n; i++)
			cin >> x[i];

		// ���� �Է�
		for (int i = 1; i <= n; i++)
			cin >> m[i];

		// �������� n-1��
		for (int i = 1; i <= n - 1; i++)
		{
			double left = x[i], right = x[i + 1], mid = 0.;

			while (left <= right - 1e-12) // 1e-12 ������ ������ ����
			{
				mid = (left + right) / 2; // �������� x��ǥ

				// ���� ��, ���� �ڼ�ü ���ܿ� ���� �η�
				double lp = left_power(i, mid), rp = right_power(i, mid);

				if (lp < rp) // ������ �ڼ�ü�� �η��� �� ���� ���
					right = mid; // �������� �� �� �������� �̵�

				else if (lp > rp) // ���� �ڼ�ü�� �η��� �� ���� ���
					left = mid; // �������� �� �� ���������� �̵�

				else 
					break;
			}
			// �Ϻ��ϰ� ���������ų� while ���� ���� ���, �ٷ� ���� ������ mid ���� �������� ��ǥ
			ans[i] = mid;
		}

		
		cout << "#" << t << ' ';
		cout << fixed;
		cout.precision(10);
		for (int i = 1; i <= n - 1; i++)
			cout << ans[i] << ' ';
		cout << endl;
	}

	return 0;
}
