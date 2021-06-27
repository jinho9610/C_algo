/* BOJ 9342 ����ü */
/* ���Խ� regex matching �̿� */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <regex>

#define endl '\n'

using namespace std;

typedef long long ll;

int T;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	// [A-F]�� A~F�� ã�´ٴ� �ǹ�
	// X?�� X�� 0ȸ �Ǵ� 1ȸ �������� �ǹ�
	// X+�� X�� 1ȸ �̻� �ݺ����� �ǹ�
	regex r(R"(^[A-F]?A+F+C+[A-F]?$)");

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		string str;
		cin >> str;
		if (regex_match(str, r)) // ���Խ��� �̿��� ���� ��Ī
			cout << "Infected!" << endl;
		else cout << "Good" << endl;
	}

	return 0;
}