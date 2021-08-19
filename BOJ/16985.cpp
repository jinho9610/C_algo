/* BOJ 16985 Maaaaaaaaaze */
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

int maze[6][6][6], parts[6][6][6], selected[6], visited[6][6][6];
int dz[] = {0, 0, 0, 0, -1, 1};
int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
const int INF = 1e9;
int ans = INF;

void rotate_arr(int h_idx) // 90도 시계 방향 회전
{
    int tmp[6][6];
    for (int i = 1; i <= 5; i++)
        for (int j = 5; j > 0; j--)
            tmp[j][5 - i + 1] = maze[h_idx][i][j];

    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            maze[h_idx][i][j] = tmp[i][j];
}

void select_arr(int h_idx, int part_num) // '판'을 선택하여 미로의 h_idx 층에 삽입
{
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            maze[h_idx][i][j] = parts[part_num][i][j];
}

typedef struct NODE
{
    int x, y, z;
    NODE(int _z, int _x, int _y)
    {
        z = _z, x = _x, y = _y;
    }
} NODE;

int bfs()
{
    memset(visited, 0xff, sizeof(visited));
    queue<NODE> q;
    q.push({1, 1, 1});
    visited[1][1][1] = 0;

    while (!q.empty())
    {
        int z = q.front().z;
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nz = z + dz[i], nx = x + dx[i], ny = y + dy[i];
            if (visited[nz][nx][ny] == -1 && maze[nz][nx][ny] == 1)
            {
                q.push({nz, nx, ny});
                visited[nz][nx][ny] = visited[z][x][y] + 1;
            }
        }
    }

    return visited[5][5][5];
}

void dfs(int h_idx)
{
    if (h_idx > 5)
    {
        // 미로 탐색 시작
        // 최소값 갱신
        if (maze[1][1][1] == 1) // (1, 1, 1)이 0이면 아예 미로 탐색 시작 조차 불가능
        {
            int move_cnt = bfs(); // (5, 5, 5)까지 탐색 진행
            if (move_cnt != -1)
                ans = min(ans, move_cnt);
        }
        return;
    }

    for (int i = 1; i <= 5; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;   // i번째 '판' 선택
            select_arr(h_idx, i); // 미로의 h_idx 층에 i번째 '판'을 삽입

            for (int d = 0; d < 4; d++) // 회전
            {
                rotate_arr(h_idx); // 미로의 h_idx 층을 90도 시계 방향 회전
                dfs(h_idx + 1);
            }

            selected[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    int num = 1;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            for (int k = 1; k <= 5; k++)
                cin >> parts[i][j][k];

    dfs(1);

    cout << ((ans == INF) ? -1 : ans) << endl;

    return 0;
}