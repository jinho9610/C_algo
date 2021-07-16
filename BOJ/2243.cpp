/* BOJ 2243 사탕 상자 */
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

const int MAX = 1000001;
int n;
ll arr[MAX];
ll tree[MAX * 4];

ll query(int node, int start, int end, int k) // 상자 안에서 k번째로 맛있는 사탕 찾기
{
	if (start == end) return end;

	int mid = (start + end) / 2;
	if (tree[node * 2] >= k)
		return query(node * 2, start, mid, k);
	else
		return query(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

void update(int node, int start, int end, int idx, ll value) // 상자 속 사탕 현황 갱신
{
	if (idx < start || idx > end) return;
	if (start == end)
	{
		tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, value);
	update(node * 2 + 1, mid + 1, end, idx, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;

	ll a, b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 1) // 사탕 꺼내기
		{
			cin >> b;
			// b번째 사탕을 꺼냈을 때, 해당 사탕의 맛을 k라고함
			int k = query(1, 1, MAX, b);
			cout << k << endl;
			// 하나 꺼냈으니 세그트리 업데이트
			update(1, 1, MAX, k, arr[k] - 1);
			arr[k]--;
		}
		else // 사탕 넣거나 버리기
		{
			cin >> b >> c;
			// b라는 맛의 사탕을
			update(1, 1, MAX, b, arr[b] + c);
			arr[b] += c; // c개 넣기 또는 빼기
		}
	}

	return 0;
}
