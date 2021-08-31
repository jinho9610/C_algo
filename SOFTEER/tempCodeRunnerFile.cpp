#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define endl '\n'

typedef long long ll;

int n, T, ans = 0;
vector<int> signals[101][101];
vector<int> lane_dirs[3];

bool visited[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void set_lane_dir()
{
    lane_dirs[0].push_back(-1);
    lane_dirs[0].push_back(0);
    lane_dirs[0].push_back(1);

    lane_dirs[1].push_back(0);
    lane_dirs[1].push_back(1);

    lane_dirs[2].push_back(-1);
    lane_dirs[2].push_back(0);
}

bool isInside(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int cnt = 0;
void dfs(int x, int y, int ld, int t)
{
    if (!visited[x][y])
    {
        cnt++;
        visited[x][y] = true;
    }
    //cout << x << ' ' << y << ' ' << t << ' ' << cnt << endl;
    // x, y는 차량 위치
    // ld - 진행(바라보는) 방향
    // t - 경과 시간
    // cnt - 밟은 교차로 개수

    // 더이상 진행하지 못하는 경우
    if (t == T)
        return;
    int signal = signals[x][y][t % 4];
    //cout << "signal - " << signal << endl;
    for (int lane_dir : lane_dirs[(signal - 1) / 4])
    {
        //cout << "land_dir - " << lane_dir << endl;
        //기본적으로 한 번은 직진을 진행함
        // cout << "[nx, ny] - "
        //      << "[" << nx << ", " << ny << "]" << endl;

        if (lane_dir == 0)
        {
            int nx = x + dx[ld], ny = y + dy[ld];
            if (!isInside(nx, ny))
                continue;
            //cnt++;
            dfs(nx, ny, ld, t + 1);
        }

        else if (lane_dir == 1 || lane_dir == -1) // 좌회전이나 우회전을 하는 경우
        {
            int new_ld = (ld + 4 + lane_dir) % 4;
            int nx = x + dx[new_ld], ny = y + dy[new_ld];

            if (!isInside(nx, ny)) // 좌회전이나 우회전 이후 맵을 빠져나간다면 스킵
                continue;

            //cnt++;
            dfs(nx, ny, new_ld, t + 1);
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    freopen("input.txt", "r", stdin);

    set_lane_dir();

    cin >> n >> T;

    // 각 교차로 별 신호입력 받기
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int a;
                cin >> a;
                signals[i][j].push_back(a);
            }
        }
    }

    if (!(signals[1][1][0] == 2 || signals[1][1][0] == 10))
    {
        cout << 1 << endl;
        return 0;
    }

    dfs(1, 1, 1, 0);
    // int x = 1, y = 1, ld = 1, t = 0, cnt = 1;
    // while (t < T)
    // {
    //     int signal = signals[x][y][t % 4];
    //     cout << "signal - " << signal << endl;
    //     for (int lane_dir : lane_dirs[(signal - 1) / 4])
    //     {
    //         //cout << "land_dir - " << lane_dir << endl;
    //         //기본적으로 한 번은 직진을 진행함
    //         // cout << "[nx, ny] - "
    //         //      << "[" << nx << ", " << ny << "]" << endl;

    //         if (lane_dir == 0)
    //         {
    //             int nx = x + dx[ld], ny = y + dy[ld];
    //             if (!isInside(nx, ny))
    //                 continue;
    //             dfs(nx, ny, ld, t + 1, cnt + 1);
    //         }

    //         else if (lane_dir == 1 || lane_dir == -1) // 좌회전이나 우회전을 하는 경우
    //         {
    //             int new_ld = (ld + 4 + lane_dir) % 4;
    //             int nx = x + dx[new_ld], ny = y + dy[new_ld];

    //             if (!isInside(nx, ny)) // 좌회전이나 우회전 이후 맵을 빠져나간다면 스킵
    //                 continue;

    //             //dfs(nx, ny, new_ld, t + 1, cnt + 1);
    //             ld = new_ld;
    //         }
    //     }
    // }

    cout << cnt << endl;

    return 0;
}