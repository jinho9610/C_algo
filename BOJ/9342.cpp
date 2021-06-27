/* BOJ 9342 염색체 */
/* 정규식 regex matching 이용 */
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

	// [A-F]는 A~F를 찾는다는 의미
	// X?는 X가 0회 또는 1회 등장함을 의미
	// X+는 X가 1회 이상 반복됨을 의미
	regex r(R"(^[A-F]?A+F+C+[A-F]?$)");

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		string str;
		cin >> str;
		if (regex_match(str, r)) // 정규식을 이용한 패턴 매칭
			cout << "Infected!" << endl;
		else cout << "Good" << endl;
	}

	return 0;
}