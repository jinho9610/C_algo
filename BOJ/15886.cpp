/* BOJ 15886 내 선물을 받아줘2 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <unordered_set>

#define endl '\n'

using namespace std;

typedef long long ll;

const int INF = 1e9;
int n;
char arr[1001], p[1001];
vector<pair<bool, int>> visited(1001);

void bfs(int s)
{
	if (visited[s].first)
		return;

	vector<int> nums;

	queue<int> q;
	q.push(s);
	visited[s].first = true;

	int mask = s;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		nums.push_back(x);

		int nx;
		if (arr[x] == 'E')
			nx = x + 1; // 동쪽 이동
		else if (arr[x] == 'W')
			nx = x - 1; // 서쪽 이동

		if (visited[nx].first == false) // 아직 방문한 적 없다면
		{
			q.push(nx);
			visited[nx].first = true;
		}
		else // 방문한적 있다면
			mask = min(mask, visited[nx].second);
	}
	for (int num : nums)
		visited[num].second = mask;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		visited[i].second = INF;

	for (int i = 1; i <= n; i++)
		bfs(i);

	unordered_set<int> us;
	for (int i = 1; i <= n; i++)
		us.insert(visited[i].second);

	cout << us.size() << endl;

	return 0;
}