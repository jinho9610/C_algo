/* SWEA 1248 �������� */
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

int t, T, v, e, s, d, cnt;
int parent[10001], visited[10001];
vector<int> child[10001];
bool found = false;

void dfs(int node)
{
	if (node == d)
	{
		found = true;
		return;
	}

	if (visited[node])
		return;

	visited[node] = true;
	for (int c : child[node])
	{
		if (!visited[c] || !found)
			dfs(c);
	}
}

void subtree_size(int node)
{
	if (visited[node])
		return;

	visited[node] = true;
	cnt++;

	for (int c : child[node])
		if (!visited[c])
			subtree_size(c);
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
		found = false, cnt = 0;
		memset(visited, 0x00, sizeof(visited));
		memset(child, 0x00, sizeof(child));
		memset(parent, 0x00, sizeof(parent));

		cin >> v >> e >> s >> d;

		for (int i = 0; i < e; i++)
		{
			int p, c;
			cin >> p >> c;
			// c�� �θ�� p�̰�, p�� �ڽ��� c�̴�
			parent[c] = p;
			child[p].push_back(c);
		}

		/*for (int i = 1; i <= v; i++)
			cout << parent[i] << ' ';
		cout << endl;*/

		// ���� ���� ã��
		int tmp_p = s;
		int common_parent = 0;
		while (tmp_p != 0)
		{
			tmp_p = parent[tmp_p]; // ������ �ϳ��� �Ž��� �ö󰡱�
			
			dfs(tmp_p); // �ش� ������ �ڼ� �߿� d�� �ִٸ� �������� ã�� ��
			
			if (found) // ���� ���� ã��
			{
				common_parent = tmp_p;
				break; // Ž�� �ߴ�
			}
		}

		memset(visited, 0x00, sizeof(visited)); // ����Ʈ�� ũ�� ���ϱ� ���� �湮 �迭 �ʱ�ȭ
		subtree_size(common_parent); // ����Ʈ�� ũ�� ����

		cout << "#" << t << " " << common_parent << " " << cnt << endl;
	}

	return 0;
}
