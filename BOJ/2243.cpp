/* BOJ 2243 ���� ���� */
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

ll query(int node, int start, int end, int k) // ���� �ȿ��� k��°�� ���ִ� ���� ã��
{
	if (start == end) return end;

	int mid = (start + end) / 2;
	if (tree[node * 2] >= k)
		return query(node * 2, start, mid, k);
	else
		return query(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

void update(int node, int start, int end, int idx, ll value) // ���� �� ���� ��Ȳ ����
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
		if (a == 1) // ���� ������
		{
			cin >> b;
			// b��° ������ ������ ��, �ش� ������ ���� k�����
			int k = query(1, 1, MAX, b);
			cout << k << endl;
			// �ϳ� �������� ����Ʈ�� ������Ʈ
			update(1, 1, MAX, k, arr[k] - 1);
			arr[k]--;
		}
		else // ���� �ְų� ������
		{
			cin >> b >> c;
			// b��� ���� ������
			update(1, 1, MAX, b, arr[b] + c);
			arr[b] += c; // c�� �ֱ� �Ǵ� ����
		}
	}

	return 0;
}
