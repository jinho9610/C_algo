/* BOJ 1012 유기농 배추 */
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define endl '\n'

typedef long long ll;

int t, T, m, n, k;
bool arr[55][55], visited[55][55];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(pair<int, int> start)
{
    queue<pair<int, int>> q;
    visited[start.first][start.second] = true;
    q.push(start);

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (isInside(nx, ny) && !visited[nx][ny] && arr[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> T;
    for (t = 1; t <= T; t++)
    {
        memset(visited, 0x00, sizeof(visited));
        memset(arr, 0x00, sizeof(arr));

        cin >> m >> n >> k;

        int r, c;
        while (k--)
        {
            cin >> c >> r;
            arr[r][c] = true;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!visited[i][j] && arr[i][j])
                    bfs({i, j}), cnt++;

        cout << cnt << endl;
    }

    return 0;
}