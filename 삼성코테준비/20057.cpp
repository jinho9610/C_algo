#include <iostream>

using namespace std;

#define endl '\n'
#define E 0
#define W 1
#define S 2
#define N 3

int total_sand = 0;
int n, arr[501][501];        // 맵의 모레 양 정보
int tx, ty;                  // 토네이도 위치의 행과 열, 초기에는 맵 중앙에 있음
int t_dir = 1, t_length = 1; // t_length만큼 토네이도 진행하고, t_length가 0되면 dir length 업데이트할걸

int dx[] = {0, 0, 1, -1}; // 동서남북
int dy[] = {1, -1, 0, 0};

// 모래가 날리는 비율
double proportion[] = {0.01, 0.01, 0.07, 0.07, 0.1, 0.1, 0.02, 0.02, 0.05};
// 모래 날리는 지점을 파악하기 위한 매핑
int sand_dx[4][10] = {
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
    {0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
    {0, 0, -1, -1, -2, -2, -1, -1, -3, -2}};
int sand_dy[4][10] = {
    {0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
    {0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}};

bool isInside(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void tonado_dir()
{
    // 현재 토네이도 방향고려
    if (t_dir == S || t_dir == N)
        t_length++;

    if (t_dir == W)
        t_dir = S;
    else if (t_dir == S)
        t_dir = E;
    else if (t_dir == E)
        t_dir = N;
    else if (t_dir == N)
        t_dir = W;
}

void check() // 밖으로 나간 모래양 체크
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            total_sand -= arr[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("s_input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j])
                total_sand += arr[i][j]; // 전체 모래양
        }
    }
    tx = n / 2 + 1, ty = n / 2 + 1;

    while (true)
    {
        for (int i = 0; i < t_length; i++)
        {
            // 토네이도 움직임
            int nx = tx + dx[t_dir], ny = ty + dy[t_dir]; // 토네이도가 갈 다음 위치
            if (arr[nx][ny] != 0)                         // 그 자리에 모레가 있다면
            {
                int moved_sand = 0;
                for (int k = 0; k < 10; k++)
                {
                    // 모래가 이동할 위치 sx, sy가 맵 안쪽에 있는지 체크하고 옮김
                    int sx = tx + sand_dx[t_dir][k], sy = ty + sand_dy[t_dir][k];
                    if (k < 9)
                    {
                        if (isInside(sx, sy))
                            arr[sx][sy] += arr[nx][ny] * proportion[k];
                        moved_sand += arr[nx][ny] * proportion[k];
                    }
                    else
                        arr[sx][sy] += arr[nx][ny] - moved_sand;
                }
            }
            // 모든 모래가 맵 밖이든 안이든 이동했으니 0
            arr[nx][ny] = 0;

            // 토네이도 위치 갱신
            tx = nx, ty = ny;
            if (tx == 1 && ty == 1)
            {
                check();
                cout << total_sand << '\n';
                return 0;
            }
        }
        // 변위만큼 돌고나면 t_length 및 방향 갱신 필요
        tonado_dir();
    }

    return 0;
}