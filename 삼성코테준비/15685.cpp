#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;
typedef long long ll;

int n;
bool arr[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0, -1,0,1 };

pii rotation(int x, int y, int cx, int cy)
{
	return { -y + cy + cx, x - cx + cy };
}

void draw_curve(vector<pii>& points)
{
	int cur_size = points.size();
	// 현재 벡터에서 가장 뒤쪽에 있는 점이 회전의 중심이 됨
	int cx = points.back().first, cy = points.back().second;

	for (int i = cur_size - 2; i >= 0; i--)
	{
		int tx = points[i].first, ty = points[i].second;
		// (tx, ty)를 (cx, cy)를 중심으로 회전하고
		pii new_pt = rotation(tx, ty, cx, cy);
		arr[new_pt.second][new_pt.first] = true;
		// 벡터에 넣는다.
		points.push_back(new_pt);
	}
}

void print_arr()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}

int check()
{
	int cnt = 0;
	for (int i = 0; i <= 100 - 1; i++)
	{
		for (int j = 0; j <= 100 -1; j++)
		{
			if (arr[i][j] && arr[i][j + 1] && arr[i + 1][j] && arr[i + 1][j + 1])
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	freopen("s_input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<pii> points;
		int ey = y + dy[d], ex = x + dx[d]; // 끝점 // 즉 0세대는 완성
		arr[y][x] = arr[ey][ex] = true;
		points.push_back({ x, y });
		points.push_back({ ex, ey });

		for (int k = 1; k <= g; k++)
			draw_curve(points);
	}

	cout << check() << endl;

	return 0;
}