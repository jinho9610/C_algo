/* BOJ 19532 수학은비대면 강의입니다 */
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

int a, b, c, d, e, f;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> a >> b >> c >> d >> e >> f;

	int x = (c * e - b * f) / (a * e - b * d);
	int y = (c * d - a * f) / (b * d - a * e);

	cout << x << ' ' << y << endl;

	return 0;
}
