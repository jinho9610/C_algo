/* SWEA 1248 공통조상 */
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
			// c의 부모는 p이고, p의 자식은 c이다
			parent[c] = p;
			child[p].push_back(c);
		}

		/*for (int i = 1; i <= v; i++)
			cout << parent[i] << ' ';
		cout << endl;*/

		// 공통 조상 찾기
		int tmp_p = s;
		int common_parent = 0;
		while (tmp_p != 0)
		{
			tmp_p = parent[tmp_p]; // 조상을 하나씩 거슬러 올라가기
			
			dfs(tmp_p); // 해당 조상의 자손 중에 d가 있다면 공통조상 찾은 것
			
			if (found) // 공통 조상 찾음
			{
				common_parent = tmp_p;
				break; // 탐색 중단
			}
		}

		memset(visited, 0x00, sizeof(visited)); // 서브트리 크기 구하기 위해 방문 배열 초기화
		subtree_size(common_parent); // 서브트리 크기 구함

		cout << "#" << t << " " << common_parent << " " << cnt << endl;
	}

	return 0;
}
