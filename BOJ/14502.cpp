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

int n, m, res, arr[9][9], arr2[9][9];
bool visited[9][9];
bool selected[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= m;
}

void virus(pair<int, int> p)
{
    queue<pair<int, int>> q;
    q.push(p);

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (isInside(nx, ny) && arr2[nx][ny] == 0)
            {
                arr2[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

void set_wall(int cnt)
{
    if (cnt == 3) // 벽 세개 설치할 때 마다
    {
        memset(arr2, 0x00, sizeof(arr2));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                arr2[i][j] = arr[i][j];

        // 바이러스 뿌리기
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (arr2[i][j] == 2)
                    virus({i, j});

        // 안전지역 세기
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                if (arr2[i][j] == 0)
                    cnt++;
        }
        res = max(res, cnt);

        return;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!selected[i][j] && arr[i][j] == 0)
            {
                selected[i][j] = true;
                arr[i][j] = 1;
                set_wall(cnt + 1);
                arr[i][j] = 0;
                selected[i][j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    // 0 빈칸, 1 벽, 2 바이러스
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    set_wall(0);
    cout << res << endl;

    return 0;
}