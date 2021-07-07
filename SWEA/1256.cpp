/* SWEQ 1256 k번째 접미어 */
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

int t, T, k;
string num;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	string name = "jinho";
	
	cin >> T;
	for (t = 1; t <= T; t++)
	{
		cin >> k >> num;

		vector<string> suffix;
		for (int i = 0; i < num.length(); i++)
			suffix.push_back(num.substr(i, num.length()));

		sort(suffix.begin(), suffix.end());

		cout << "#" << t << " " << suffix[k - 1] << endl;
	}

	return 0;
}
