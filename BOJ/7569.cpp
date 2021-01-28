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

int n, m, h, arr[101][101][101];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

queue<pair<int, pair<int, int>>> q;

bool isInside(int z, int x, int y)
{
    return 0 < z && z <= h && 0 < x && x <= n && 0 < y && y <= m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> h;

    bool flag = true; // 처음부터 모두 익어 있는 상태인지 확인
    for (int k = 1; k <= h; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[k][i][j];
                if (arr[k][i][j] == 0) // 하나라도 안 익은 토마토가 있다면
                    flag = false;
                if (arr[k][i][j] == 1)
                    q.push({k, {i, j}});
            }
        }
    }
    if (flag) // 모두 익어있는 상태라면
    {
        cout << 0 << '\n';
        return 0;
    }

    int cnt = -1;
    while (!q.empty())
    {
        cnt++;
        int size = q.size();

        while (size--)
        {
            int z = q.front().first, x = q.front().second.first, y = q.front().second.second;
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                int nz = z + dz[i], nx = x + dx[i], ny = y + dy[i];

                if (isInside(nz, nx, ny) && arr[nz][nx][ny] == 0)
                {
                    arr[nz][nx][ny] = arr[z][x][y] + 1;
                    q.push({nz, {nx, ny}});
                }
            }
        }
    }

    for (int k = 1; k <= h; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (arr[k][i][j] == 0) // 안익은 토마토 발견하면
                {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}