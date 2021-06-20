/* BOJ 16938 �༺ ���� */
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
				if (i > j) // ����h �����̹Ƿ�, �ߺ��Ǵ� ������ �����ϰ� edges�� ����
					edges.push_back({ {i, j}, arr[i][j] });
			}
		}

	for (int i = 1; i <= n; i++) // �θ� �迭 �ʱ�ȭ
		p[i] = i;
	
	sort(edges.begin(), edges.end(), cmp); // ������ (��� ����) �������� ����

	ll ans = 0;
	for (auto edge : edges) // ���ĵ� ���� ���տ��� ������ �ϳ��� ���´�
	{
		// ����Ŭ�� �������
		if (find_parent(p[edge.first.first]) != find_parent(p[edge.first.second]))
		{
			union_parent(p[edge.first.first], p[edge.first.second]); // ����Ŭ�� ���ٸ� �ϳ��� �������� ��ġ��
			ans += edge.second; // �� ���� ����� ���Ѵ�. -> ���� ȿ������ flow �Ǽ� ����� ���ϴ� ����
		}
	}

	cout << ans << endl;

	return 0;
}
