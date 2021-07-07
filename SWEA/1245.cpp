/* swea 1245 균형점 */
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

double left_power(int p, double bp_x) // 왼쪽 자성체로부터의 인력
{
	double lp = 0.;
	// bp_x는 균형점의 x 좌표
	for (int i = 1; i <= p; i++)
	{
		double d = bp_x - x[i];
		lp += (m[i] / (d * d));
	}

	return lp;
}

double right_power(int p, double bp_x) // 오른쪽 자성체로부터의 인력
{
	double rp = 0.;
	// bp_x는 균형점의 x 좌표
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
		// 좌표 입력
		for (int i = 1; i <= n; i++)
			cin >> x[i];

		// 질량 입력
		for (int i = 1; i <= n; i++)
			cin >> m[i];

		// 균형점은 n-1개
		for (int i = 1; i <= n - 1; i++)
		{
			double left = x[i], right = x[i + 1], mid = 0.;

			while (left <= right - 1e-12) // 1e-12 이하의 오차는 무시
			{
				mid = (left + right) / 2; // 균형점의 x좌표

				// 각각 좌, 우측 자성체 집단에 의한 인력
				double lp = left_power(i, mid), rp = right_power(i, mid);

				if (lp < rp) // 오른쪽 자성체의 인력이 더 강한 경우
					right = mid; // 균형점을 좀 더 왼쪽으로 이동

				else if (lp > rp) // 왼쪽 자성체의 인력이 더 강한 경우
					left = mid; // 균형점을 좀 더 오른쪽으로 이동

				else 
					break;
			}
			// 완벽하게 동일해지거나 while 문이 끝난 경우, 바로 이전 스텝의 mid 값이 균형점의 좌표
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
