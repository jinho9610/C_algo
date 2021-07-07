/* SWEA 1257 K��° ���ڿ� */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <set>

#define endl '\n'

using namespace std;

typedef long long ll;

int t, T, k;
string str;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		cin >> k >> str;

		set<string> s; // ���� // ���԰� ���ÿ� ���ĵ�

		for (int i = 0; i < str.length(); i++)
			for (int j = 0; j < str.length(); j++)
				s.insert(str.substr(i, j + 1)); // ��� �κ� ���ڿ����� ����

		cout << "#" << t << ' ';
		if (s.size() < k) // K��° ���Ұ� ���� ��� none ���
			cout << "none" << endl;
		else
		{
			set<string>::iterator iter = s.begin(); // ù��° ���� ����Ű�� �ݺ���
			for (int i = 0; i < k - 1; i++)
				iter++; // ���տ��� K��° ���� ���
			cout << *iter << endl;
		}
	}

	return 0;
}
