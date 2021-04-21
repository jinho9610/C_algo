// 풀이에 사용된 알고리즘:

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

typedef long long ll;

int n, m, arr[501][501];
bool visited[501][501];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= m;
}

int max_val = 0;
void dfs(int x, int y, int cnt, int sum)
{
    if (cnt == 4)
    {
        max_val = max(max_val, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (!visited[nx][ny] && isInside(nx, ny))
        {
            visited[nx][ny] = true;
            dfs(nx, ny, cnt + 1, sum + arr[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

int special(int x, int y)
{
    int tmp_max = 0;

    // ㅗ
    if (0 < x - 1 && 0 < y - 1 && y + 1 <= m)
        tmp_max = max(tmp_max, arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x][y + 1]);
    // ㅏ
    if (0 < x - 1 && x + 1 <= n && y + 1 <= m)
        tmp_max = max(tmp_max, arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y + 1]);
    // ㅓ
    if (0 < y - 1 && x - 1 > 0 && x + 1 <= n)
        tmp_max = max(tmp_max, arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y - 1]);
    // ㅜ
    if (y - 1 > 0 && y + 1 <= m && x + 1 <= n)
        tmp_max = max(tmp_max, arr[x][y] + arr[x + 1][y] + arr[x][y - 1] + arr[x][y + 1]);

    return tmp_max;
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

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            visited[i][j] = true;
            max_val = 0;
            dfs(i, j, 0, 0);
            res = max(res, max(special(i, j), max_val));
            visited[i][j] = false;
        }
    }

    cout << res << '\n';

    return 0;
}