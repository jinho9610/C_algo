/* SWEA 1251 �ϳ��� */
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
double e; // ����
ll dist[1001][1001];
pair<ll, ll> islands[1001]; // �ִ� 1000���� ��
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

	for (int i = 1; i <= n; i++) // �ߺ� ������ ���ؼ� ������� �� ��λﰢ��ĸ� ���� 
		for (int j = i + 1; j <= n; j++) // �� a���� �� a�� ���� ������ ����� �ʿ� ����
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
		edges.clear(); // ���� �迭 �ʱ�ȭ

		cin >> n;
		for (int i = 1; i <= n; i++) // x
			cin >> islands[i].first;
		for (int i = 1; i <= n; i++) // y
			cin >> islands[i].second;

		for (int i = 1; i <= n; i++) // �θ� �迭 �ʱ�ȭ
			p[i] = i;

		cin >> e;

		// ��� ��-to-�� �Ÿ� ���� �ľ�
		island_distance();

		// ũ�罺Į �˰���
		sort(edges.begin(), edges.end(), cmp); // ���� ���� �������� ����

		double tot_fair = 0.; // ��� ���� �����ϴµ� �ʿ���, �� ȯ��δ��
		for (const auto edge : edges)
		{
			int i1 = edge.first.first, i2 = edge.first.second; // i1�� i2�� �����ϴ� ����
			ll L2 = edge.second; // i1�� i2�� �����ϴµ� �ʿ��� ȯ��δ��

			if (find_parent(i1) == find_parent(i2)) // ����Ŭ ������ ���
				continue; // �ش� ���� ����


			union_parent(i1, i2); // �� �� ���� (���� ���տ� ���Խ�Ŵ)
			tot_fair += L2 * e;
		}

		cout << "#" << t << ' ' << tot_fair << endl;
	}
	
	return 0;
}