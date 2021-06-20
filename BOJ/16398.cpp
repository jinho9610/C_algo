/* BOJ 16938 행성 연결 */
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

int n, p[1001], arr[1001][1001];
vector<pair<pair<int, int>, int>> edges;

int find_parent(int x)
{
	if (p[x] != x)
		p[x] = find_parent(p[x]);

	return p[x];
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a > b)
		p[a] = b;
	else p[b] = a;
}

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	if (p1.second == p2.second)
		return p1.first.first < p1.first.first;
	else
		return p1.second < p2.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			{
				cin >> arr[i][j];
				if (i > j) // 양방햔 간선이므로, 중복되는 간선은 제외하고 edges에 삽입
					edges.push_back({ {i, j}, arr[i][j] });
			}
		}

	for (int i = 1; i <= n; i++) // 부모 배열 초기화
		p[i] = i;
	
	sort(edges.begin(), edges.end(), cmp); // 간선의 (비용 기준) 오름차순 정렬

	ll ans = 0;
	for (auto edge : edges) // 정렬된 간선 집합에서 간선을 하나씩 빼온다
	{
		// 사이클이 없어야함
		if (find_parent(p[edge.first.first]) != find_parent(p[edge.first.second]))
		{
			union_parent(p[edge.first.first], p[edge.first.second]); // 사이클이 없다면 하나의 집합으로 합치고
			ans += edge.second; // 그 때의 비용을 더한다. -> 가장 효율적인 flow 건설 비용을 구하는 과정
		}
	}

	cout << ans << endl;

	return 0;
}
