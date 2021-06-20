#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, dp[501][501], path[501][501];
vector<pair<int, int>> mat(501);

int minCalc(int i, int j)
{
	if (i == j)
		return 0;

	if (dp[i][j])
		return dp[i][j];

	int tmp_min_val = 1e9, tmp_min_idx = i;
	for (int k = i; k < j; k++)
	{
		int tmp = minCalc(i, k) + minCalc(k + 1, j) + mat[i].first * mat[k].second * mat[j].second;
		if (tmp_min_val > tmp)
		{
			tmp_min_val = tmp;
			tmp_min_idx = k;
		}
	}

	path[i][j] = tmp_min_idx;
	return dp[i][j] = tmp_min_val;
}

void order(int i, int j)
{
	if (i == j)
		cout << "A" << i;
	else
	{
		int k = path[i][j];
		cout << "(";
		order(i, k);
		order(k + 1, j);
		cout << ")";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int r, c;
		cin >> r >> c;
		
		mat[i] = { r, c };
	}

	cout << minCalc(1, n) << endl;

	order(1, n);

	return 0;
}