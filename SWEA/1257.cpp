/* SWEA 1257 K번째 문자열 */
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

		set<string> s; // 집합 // 삽입과 동시에 정렬됨

		for (int i = 0; i < str.length(); i++)
			for (int j = 0; j < str.length(); j++)
				s.insert(str.substr(i, j + 1)); // 모든 부분 문자열들을 삽입

		cout << "#" << t << ' ';
		if (s.size() < k) // K번째 원소가 없는 경우 none 출력
			cout << "none" << endl;
		else
		{
			set<string>::iterator iter = s.begin(); // 첫번째 원소 가리키는 반복자
			for (int i = 0; i < k - 1; i++)
				iter++; // 집합에서 K번째 원소 출력
			cout << *iter << endl;
		}
	}

	return 0;
}
