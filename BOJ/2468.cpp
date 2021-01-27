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

int n, arr[101][101], visited[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= n;
}

void bfs(pair<int, int> p1, int h)
{
    queue<pair<int, int>> q;
    q.push({p1.first, p1.second});
    visited[p1.first][p1.second] = true;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (isInside(nx, ny) && !visited[nx][ny] && arr[nx][ny] > h) // 맵 안에 있고, 방문한적 없고, 지대 높이가 물 높이보다 높은 경우
            {
                visited[nx][ny] = true; // 방문처리하고
                q.push({nx, ny});       // q에 푸시하고
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int min_h = 1e9, max_h = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            min_h = min(min_h, arr[i][j]);
            max_h = max(max_h, arr[i][j]);
        }
    }

    int ans = 0;
    for (int h = 0; h <= max_h; h++) // 물의 높이 변경
    {
        int cnt = 0;
        memset(visited, 0x00, sizeof(visited));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!visited[i][j] && arr[i][j] > h)
                {
                    bfs({i, j}, h);
                    cnt++;
                }
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}