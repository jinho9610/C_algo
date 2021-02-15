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

const int INF = 1e9;
int n, m, ans = INF, cctv_cnt, arr[9][9], tmp[9][9];

int cctv_dir[9]; // cctv별 방향

int dx[] = {0, 0, 1, -1}; // 동 서 남 북
int dy[] = {1, -1, 0, 0};

vector<pair<int, int>> cctv;

void copyMap()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            tmp[i][j] = arr[i][j];
}

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= m;
}

void detect(int x, int y, int d)
{
    int nx = x, ny = y;

    while (true)
    {
        nx += dx[d], ny += dy[d];

        if (!isInside(nx, ny))
            break; // 맵빠져나가면 감시 종료

        if (tmp[nx][ny] == 0)
            tmp[nx][ny] = 100; // 100은 이미 감시가 끝난 지점

        else if (tmp[nx][ny] == 6) // 벽 만나면 감시 종료
            break;
    }
}

void set_cctv()
{
    for (int i = 0; i < cctv.size(); i++) // cctv의 개수만큼
    {
        int x = cctv[i].first, y = cctv[i].second;

        switch (tmp[x][y]) // cctv의 번호에 따라서 switch문
        {
        case 1:
            detect(x, y, cctv_dir[i]);
            break;

        case 2:
            if (cctv_dir[i] == 0)
            {
                // 동서 감시
                detect(x, y, 0);
                detect(x, y, 1);
            }
            else if (cctv_dir[i] == 1)
            {
                // 남북 감시
                detect(x, y, 2);
                detect(x, y, 3);
            }

            break;

        case 3:
            if (cctv_dir[i] == 0)
            {
                detect(x, y, 0);
                detect(x, y, 3);
            }
            else if (cctv_dir[i] == 1)
            {
                detect(x, y, 1);
                detect(x, y, 2);
            }
            else if (cctv_dir[i] == 2)
            {
                detect(x, y, 0);
                detect(x, y, 2);
            }
            else if (cctv_dir[i] == 3)
            {
                detect(x, y, 3);
                detect(x, y, 1);
            }
            break;

        case 4:
            if (cctv_dir[i] == 0)
            {
                detect(x, y, 1);
                detect(x, y, 2);
                detect(x, y, 3);
            }
            else if (cctv_dir[i] == 1)
            {
                detect(x, y, 0);
                detect(x, y, 2);
                detect(x, y, 3);
            }
            else if (cctv_dir[i] == 2)
            {
                detect(x, y, 0);
                detect(x, y, 1);
                detect(x, y, 3);
            }
            else if (cctv_dir[i] == 3)
            {
                detect(x, y, 0);
                detect(x, y, 1);
                detect(x, y, 2);
            }
            break;

        case 5:
            if (cctv_dir[i] == 0)
            {
                detect(x, y, 0);
                detect(x, y, 1);
                detect(x, y, 2);
                detect(x, y, 3);
            }
            break;

        default:
            break;
        }
    }
}

int getBlindSpots() // 현재 cctv 배치에서 사각지대의 개수 반환
{
    int cnt = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (tmp[i][j] == 0)
                cnt++;

    return cnt;
}

void dfs(int idx, int cnt)
{
    if (cnt == cctv.size()) // 모든 cctv의 방향을 지정한 경우
    {
        copyMap();
        set_cctv();
        ans = min(ans, getBlindSpots());

        return;
    }

    int x = cctv[idx].first, y = cctv[idx].second; // 현재 cctv의 위치

    for (int i = 0; i < 4; i++)
    {
        if (arr[x][y] == 2 && i > 1) // 두가지 경우에 대해서만 생각하면 됨
            continue;
        if (arr[x][y] == 5 && i > 0) // 한가지 경우에 대해서만 생각하면 됨
            continue;

        cctv_dir[idx] = i;
        dfs(idx + 1, cnt + 1);
        cctv_dir[idx] = 5; // 무의미한 방향으로 바꾼다
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] > 0 && arr[i][j] < 6)
                cctv.push_back({i, j});
        }
    }

    ans = INF;

    dfs(0, 0);

    cout << ans << endl;

    return 0;
}