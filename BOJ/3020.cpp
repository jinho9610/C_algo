/* BOJ 3020 °³¶Ë¹ú·¹ */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>

#define endl '\n'

using namespace std;

typedef long long ll;

int n, h;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> h;
	vector<int> bot(n / 2), top(n / 2);

	for (int i = 0; i < n / 2; i++)
		cin >> bot[i], cin >> top[i];

	sort(bot.begin(), bot.end());
	sort(top.begin(), top.end());

	int cnt = 0, min_val = 1e9;
	for (int i = 1; i <= h; i++)
	{
		auto bot_iter = lower_bound(bot.begin(), bot.end(), i);
		auto top_iter = lower_bound(top.begin(), top.end(), h - i + 1);

		int cand = distance(bot_iter, bot.end()) + distance(top_iter, top.end());

		if (cand == min_val)
			cnt++;
		
		if (cand < min_val)
		{
			min_val = cand;
			cnt = 1;
		}
	}

	cout << min_val << ' ' << cnt << endl;
	
	return 0;
}
