/* BOJ 6236 �뵷 ���� */
/* ����Ž��, �Ķ��Ʈ�� ��ġ */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const int INF = 1e9;
int money[100001], n, m, ans = INF;

bool check_answer(int k)
{
	// 1~n��° ������, ���� �� k��ŭ�� �� ��ư� �� �ִ� ��
	int balance = 0; // �ܰ�
	int cnt = 0; // ���� Ƚ��
	int need = 0; // i��° ���� ��ư��� ���� �ʿ��� ����
	for (int i = 1; i <= n; i++)
	{
		need = money[i];
		if (need > k) // ������ �� �ִ� �ݾ׺��� ū ������ �ʿ��ϸ� ��Ȱ �Ұ�
			return false;

		if (balance < need) // �ʿ� ���꺸�� �ܰ� ���� ���ٸ�
		{
			balance = k - need; // ��� ���� �ְ� k��ŭ ���� �� �Һ�
			cnt++; // ���� Ƚ�� ����
		}
		else // �ܰ�� ����� ��ư� �� �ִٸ�
			balance -= need; // ���� ���� �Һ�
	}
	return cnt <= m;
}

void binary_search(int left, int right)
{
	if (left > right)
		return; // Ž�� ����

	int k = (left + right) / 2;

	if (check_answer(k)) // k�ε� ��ư� �� �ִٸ�
		ans = min(k, ans), binary_search(left, k - 1); // ���� �� ���� �ݾ��� �����ϴ� ������ε� ��ư� �� �ִ� �� �ľ�
	else // �� �� ���� �� k�δ� �� ��ư��ٸ�, k ����
		binary_search(k + 1, right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> money[i];

	binary_search(0, INF);
	cout << ans << endl;

	return 0;
}
