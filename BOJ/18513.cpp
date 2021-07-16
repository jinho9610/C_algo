/* BOJ 18513 ���� */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <set>
#include <unordered_set>

#define endl '\n'

using namespace std;

typedef long long ll;

int n, k;
queue<int> q;
unordered_set<int> s;
int dx[] = { 1, -1 };

ll bfs()
{
	ll distance = 1, cnt = 0, ans = 0;
	while (!q.empty())
	{
		int q_size = q.size();
		while (q_size--)
		{
			int cur = q.front();
			q.pop();

			for (int i = 0; i < 2; i++)
			{
				int next = cur + dx[i];
				// �湮���� ����
				//=���� ��ġ���� �ʾҰų�, ������ �ƴ� ��ǥ�� ���
				if (!(s.count(next) >= 1))
				{
					s.insert(next); // �湮ó���ϰ�
					q.push(next); // ť�� ����
			
					cnt++; // ��ġ�� ���� �� 1 ����
					ans += distance; // ���൵ ��� �� �ջ�

					if (cnt == k) // k���� ���� ��� ��ġ�� ���
						return ans; // �� ���൵ ��ȯ

				}
			}
		}
		distance++; // ���൵ ������ ����, ���� ����� ���������� �Ÿ�
	}
	return ans; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		q.push(a);
		s.insert(a); // �湮ó��
	}

	ll ans = bfs();

	cout << ans << endl;
	
	return 0;
}
