/* SWEA 1251 하나로 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;

const int INF = 1e9;
int t, T, n, p[1001];
double e; // 세율
ll dist[1001][1001];
pair<ll, ll> islands[1001]; // 최대 1000개의 섬
vector<pair<pair<ll, ll>, ll>> edges;

void island_distance()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dist[i][j] = 0;
			else
			{
				ll dx = islands[i].first - islands[j].first;
				ll dy = islands[i].second - islands[j].second;
				dist[i][j] = dx * dx + dy * dy;
			}
		}
	}

	for (int i = 1; i <= n; i++) // 중복 방지를 위해서 인접행렬 중 상부삼각행렬만 포함 
		for (int j = i + 1; j <= n; j++) // 섬 a에서 섬 a로 가는 간선은 고려할 필요 없음
			edges.push_back({ {i, j}, dist[i][j] });
}

// find
int find_parent(int x)
{
	if (x == p[x])
		return x;
	return p[x] = find_parent(p[x]);
}

// union
void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b)
		p[b] = a;
	else
		p[a] = b;
}

bool cmp(pair<pair<int, int>, ll> p1, pair<pair<int, int>, ll> p2)
{
	return p1.second < p2.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cout << fixed;
	cout.precision(0);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		edges.clear(); // 간선 배열 초기화

		cin >> n;
		for (int i = 1; i <= n; i++) // x
			cin >> islands[i].first;
		for (int i = 1; i <= n; i++) // y
			cin >> islands[i].second;

		for (int i = 1; i <= n; i++) // 부모 배열 초기화
			p[i] = i;

		cin >> e;

		// 모든 섬-to-섬 거리 관계 파악
		island_distance();

		// 크루스칼 알고리즘
		sort(edges.begin(), edges.end(), cmp); // 간선 정보 오름차순 정렬

		double tot_fair = 0.; // 모든 섬을 연결하는데 필요한, 총 환경부담금
		for (const auto edge : edges)
		{
			int i1 = edge.first.first, i2 = edge.first.second; // i1과 i2를 연결하는 간선
			ll L2 = edge.second; // i1과 i2를 연결하는데 필요한 환경부담금

			if (find_parent(i1) == find_parent(i2)) // 싸이클 생성할 경우
				continue; // 해당 간선 무시


			union_parent(i1, i2); // 두 섬 연결 (같은 집합에 포함시킴)
			tot_fair += L2 * e;
		}

		cout << "#" << t << ' ' << tot_fair << endl;
	}
	
	return 0;
}