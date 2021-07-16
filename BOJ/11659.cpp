/* BOJ 11659 구간 합 구하기4 */
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

int n, m, arr[100001];
vector<int> tree;

ll make_segtree(int start, int end, int node)
{
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = make_segtree(start, mid, node * 2) + make_segtree(mid + 1, end, node * 2 + 1);
}

ll query(int start, int end, int node, int left, int right)
{
	// 구하려는 범위가, 노드의 구간을 벗어나는 경우
	if (left > end || right < start) return 0;
	
	// 노드의 구간이, 구하려는 범위에 포함되는 경우
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	tree.resize(n * 4);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	make_segtree(1, n, 1); // 구간합 트리 생성

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << query(1, n, 1, a, b) << endl;
	}

	return 0;
}
