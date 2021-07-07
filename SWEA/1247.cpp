/* SWEA 1247 최적 경로 */
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

int t, T, n, ans = 1e9;
pair<int, int> company, house, customers[11];
bool visited[11];
vector<pair<int, int>> path;

int dist(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void dfs(int cnt)
{
	// cnt는 방문한 고객의 수
	// recent는 가장 최근에 방문한 고객 번호
	// length는 현재까지의 경로
	
	if (cnt == n) // n개 고객을 모두 방문한 경우
	{
		int tmp_length = 0;
		for (int i = 0; i < path.size(); i++)
		{
			if (i == 0)
				tmp_length += dist(company, path[i]);
			else // 이전에 방문한 고객과의 거리를 더함
				tmp_length += dist(path[i - 1], path[i]);
		}
		tmp_length += dist(path[path.size() - 1], house);

		ans = min(ans, tmp_length);

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			path.push_back(customers[i]);

			dfs(cnt + 1);

			path.pop_back();
			visited[i] = false;
		}
	}
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
		ans = 1e9; // 최소값 초기화
		memset(visited, 0x00, sizeof(visited));

		cin >> n;
		cin >> company.first >> company.second;
		cin >> house.first >> house.second;

		for (int i = 1; i <= n; i++)
			cin >> customers[i].first >> customers[i].second;

		dfs(0);

		cout << "#" << t << ' ' << ans << endl;
	}

	return 0;
}
