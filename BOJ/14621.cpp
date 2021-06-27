/* BOJ ���� �ȵǴ� ���� */
/* MST - ũ�罺Į */
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
		p[i] = i; // �θ� �迭 �ʱ�ȭ
		cin >> school_types[i];
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d; // u <-> v�� d��ŭ ������

		if (school_types[u] != school_types[v]) // ����<->���� �Ǵ� ����<->���ʰ� �ƴ� ���
			edges.push_back({ {u, v}, d }); // ���ǹ��� �����̹Ƿ� �����׷쿡 ����
	}

	sort(edges.begin(), edges.end(), cmp); // �������� ��� ���� �������� ����
	
	int ans = 0, cnt = 0;
	for (auto edge : edges)
	{
		int u = edge.first.first;
		int v = edge.first.second;
		int d = edge.second;

		if (find_parent(u) != find_parent(v))
		{
			// u�� v�� �ٸ� ���տ� ���Ѵٸ�, �� ����Ŭ�� �߻���Ű�� �ʴ´ٸ�
			union_parent(u, v);
			ans += d;
			if (++cnt == n - 1) // ��� ���е��� �� �� �� �ֱ� ���ؼ��� (����-1)�� ������ �ʿ�
			{
				cout << ans << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl; // ��� ������ �����ϴ� MST ã�� ���ϸ� -1 ���

	return 0;
}
