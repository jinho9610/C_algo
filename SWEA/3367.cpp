/* SWEA 3367 갤럭시 S9 */
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

int t, T, k, arr[3001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		vector<int> parts;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			int a;
			cin >> a;
			parts.push_back(a);
		}

		int cost = 0;
		while (parts.size() > 1)
		{
			cout << parts.size() << endl;
			// 인접한 녀석과 합해서 가장 최소인 지점 찾아야함
			int min_idx = 0, min_val = 1e9;
			for (int i = 0; i < parts.size() - 1; i++)
			{
				int tmp_sum = parts[i] + parts[i + 1];
				if (tmp_sum < min_val)
				{
					min_val = tmp_sum;
					min_idx = i;
				}
			}

			// min_idx와 min_idx + 1을 삭제
			parts.erase(parts.begin() + min_idx, parts.begin()+min_idx + 2);
			parts.insert(parts.begin() + min_idx, min_val);

			cost += min_val;
		}
		cout << cost << endl;
	}

	return 0;
}
