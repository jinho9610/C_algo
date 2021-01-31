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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= m;
}

int dfs(int x, int y, int cnt)
{
    if (cnt == 4)
        return arr[x][y];

    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isInside(nx, ny) && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            sum = max(sum, arr[x][y] + dfs(nx, ny, cnt + 1));
            visited[nx][ny] = false;
        }
    }

    return sum;
}

int Oh()
{
    int result = 0;

    for (int i = 1; i <= n - 1; i++) // ㅗ
        for (int j = 2; j <= m - 1; j++)
            result = max(result, arr[i][j] + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1]);

    for (int i = 2; i <= n - 1; i++) // ㅏ
        for (int j = 1; j <= m - 1; j++)
            result = max(result, arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j + 1]);

    for (int i = 1; i <= n - 1; i++) // ㅜ
        for (int j = 2; j <= m - 1; j++)
            result = max(result, arr[i][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j]);

    for (int i = 2; i < n - 1; i++) // ㅓ
        for (int j = 2; j <= m; j++)
            result = max(result, arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1]);

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    int result = Oh();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            visited[i][j] = arr[i][j];
            result = max(result, dfs(i, j, 1));
            visited[i][j] = 0;
        }
    }

    cout << result << '\n';

    return 0;
}