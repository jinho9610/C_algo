/* BOJ 나만 안되는 연애 */
/* MST - 크루스칼 */
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

int n, m, p[1001];
char school_types[1001];
vector<pair<pair<int, int>, int>> edges;

// find
int find_parent(int x)
{
	if (p[x] == x)
		return x;
	
	return p[x] = find_parent(p[x]);
}

// union
void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b)
		p[a] = b;
	else
		p[b] = a;
}

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	return p1.second < p2.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i; // 부모 배열 초기화
		cin >> school_types[i];
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d; // u <-> v는 d만큼 떨어짐

		if (school_types[u] != school_types[v]) // 남초<->남초 또는 여초<->여초가 아닌 경우
			edges.push_back({ {u, v}, d }); // 유의미한 간선이므로 간선그룹에 포함
	}

	sort(edges.begin(), edges.end(), cmp); // 간선들의 비용 기준 오름차순 정렬
	
	int ans = 0, cnt = 0;
	for (auto edge : edges)
	{
		int u = edge.first.first;
		int v = edge.first.second;
		int d = edge.second;

		if (find_parent(u) != find_parent(v))
		{
			// u와 v가 다른 집합에 속한다면, 즉 싸이클을 발생시키지 않는다면
			union_parent(u, v);
			ans += d;
			if (++cnt == n - 1) // 모든 대학들을 다 갈 수 있기 위해서는 (노드수-1)의 간선이 필요
			{
				cout << ans << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl; // 모든 대학을 연결하는 MST 찾지 못하면 -1 출력

	return 0;
}
