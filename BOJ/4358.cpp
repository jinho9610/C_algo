/* BOJ 4358 ������ */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <map>

#define endl '\n'

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	map<string, int> m;

	string wood; // ���� �̸� �Է¹ޱ� ���� ���ڿ�
	int cnt = 0; // �� ���� �׷� �� 
	while (getline(cin, wood))
		m[wood]++, cnt++; // �ش� ���� �׷� �� 1 ����, ��ü ���� �� 1 ����

	cout << fixed;
	cout.precision(4); // �Ҽ����Ʒ� ��°�ڸ������� ǥ���ϵ��� ����
	for (auto i = m.begin(); i != m.end(); i++) // �� �� ��ü ���� ���
		cout << i->first << ' ' << i->second * 100 / (double)cnt << endl;

	cout << 1.34502 << endl;
	return 0;
}


