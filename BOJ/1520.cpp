/* */
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>

using namespace std;

#define endl '\n'

typedef long long ll;

int arr[501][501], n, m, dp[501][501];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int dfs(int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];

    if (x == 1 && y == 1)
        return 1;

    //int &ret = dp[x][y];
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (isInside(nx, ny) && (arr[nx][ny] > arr[x][y]))
            dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    memset(dp, 0xff, sizeof(dp));

    cout << dfs(n, m) << endl;

    return 0;
}