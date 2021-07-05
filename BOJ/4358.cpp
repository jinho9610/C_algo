/* BOJ 4358 생태학 */
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

	string wood; // 나무 이름 입력받기 위한 문자열
	int cnt = 0; // 총 나무 그루 수 
	while (getline(cin, wood))
		m[wood]++, cnt++; // 해당 나무 그루 수 1 증가, 전체 나무 수 1 증가

	cout << fixed;
	cout.precision(4); // 소수점아래 넷째자리까지만 표현하도록 고정
	for (auto i = m.begin(); i != m.end(); i++) // 맵 내 전체 원소 출력
		cout << i->first << ' ' << i->second * 100 / (double)cnt << endl;

	cout << 1.34502 << endl;
	return 0;
}


