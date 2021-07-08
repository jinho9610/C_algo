/* BOJ 20542 받아쓰기 */
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

int n, m;
string source, target;
vector<vector<int>> dp;

bool is_equal(char source_c, char target_c)
{
	if (source_c == 'i')
	{
		if (target_c == 'i' || target_c == 'j' || target_c == 'l')
			return true;
		else return false;
	}
	else if (source_c == 'v')
	{
		if (target_c == 'v' || target_c == 'w')
			return true;
		else
			return false;
	}
	else
		return source_c == target_c;
}

int levenshtein_distance(string source, string target)
{
	for (int i = 0; i < target.length(); i++)
	{
		for (int j = 0; j < source.length(); j++)
		{
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else
			{
				int replace_cost = 0;
				if (!is_equal(source[j], target[i]))
					replace_cost = 1;

				dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + replace_cost));
			}
		}
	}
	return dp[m][n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	cin >> source >> target;

	source = " " + source, target = " " + target;

	dp.resize(m + 1);
	for (int i = 0; i < m + 1; i++)
		dp[i].resize(n + 1);

	cout << levenshtein_distance(source, target) << endl;

	return 0;
}
