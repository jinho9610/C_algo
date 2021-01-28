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

int n, m, arr[301][301];
bool visited[303][303];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= m;
}

void bfs(pair<int, int> p1)
{
    queue<pair<int, int>> q;
    q.push(p1);
    visited[p1.first][p1.second] = true;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (isInside(nx, ny) && !visited[nx][ny] && arr[nx][ny] != 0)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void after_1year(pair<int, int> p)
{
    queue<pair<int, int>> q;
    q.push(p);
    visited[p.first][p.second] = true;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (isInside(nx, ny) && !visited[nx][ny])
            {
                if (arr[nx][ny] > 0)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
                else
                    cnt++; // 바다 개수 증가
            }
        }

        if (arr[x][y] <= cnt)
            arr[x][y] = 0;
        else
            arr[x][y] -= cnt;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    int y = 0;
    while (true)
    {
        memset(visited, 0x00, sizeof(visited));

        int cnt = 0;
        bool isAllMelt = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (arr[i][j]) // 빙산이 존재한다면
                    isAllMelt = false;

                if (!visited[i][j] && arr[i][j] > 0)
                {
                    after_1year({i, j});
                    cnt++;
                    if (cnt > 1)
                    {
                        cout << y << '\n';
                        return 0;
                    }
                }
            }
        }

        if (isAllMelt)
        {
            cout << 0 << '\n';
            return 0;
        }

        y++;
    }

    return 0;
}