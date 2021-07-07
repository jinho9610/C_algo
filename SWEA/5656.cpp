#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define endl '\n'

typedef long long ll;

int result = 1e9;
int n, w, h;
int real_arr[16][13], arr[16][13], selected[5], visited[16][13];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y)
{
    return 0 < x && x <= h && 0 < y && y <= w;
}

void copy_arr() // 배열 복사
{
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            arr[i][j] = real_arr[i][j];
}

void break_blocks(pair<int, int> start)
{
    int x = start.first, y = start.second;
    visited[x][y] = true;
    int len = arr[x][y] - 1; // 퍼져나갈 길이

    for (int i = 0; i < 4; i++) // 사방으로 퍼져나갈것
    {
        for (int j = 1; j <= len; j++)
        {
            int nx = x + dx[i] * j, ny = y + dy[i] * j;

            if (isInside(nx, ny) && !visited[nx][ny])
                break_blocks({nx, ny});
        }
    }
    arr[x][y] = 0;
}

void refresh_blocks()
{
    for (int i = 1; i <= w; i++) // 열단위로 접근
    {
        bool flag = false;
        vector<int> v;

        int cnt = 0;
        for (int j = h; j > 0; j--)
        {
            arr[j + cnt][i] = arr[j][i];
            arr[j][i] = 0;
            if (arr[j][i] == 0)
                cnt++;
        }
    }
}

void shoot_ball()
{
    for (int pos : selected) // 쏠 위치
    {
        memset(visited, 0x00, sizeof(visited));
        pair<int, int> start;

        for (int i = 1; i <= h; i++)
        {
            if (arr[i][pos] != 0)
            {
                start = {i, pos};
                break;
            }
        }

        break_blocks(start);
        refresh_blocks();
    }
}

// 구슬 쏠 위치 중복순열로 구하기
void selection(int cnt)
{
    if (cnt == n)
    {
        // 쏠 자리 모두 정했으니 쏜다
        // arr 변경될 것이니 임시 배열로 복사
        copy_arr();
        shoot_ball();

        int tmp = 0;
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                if (arr[i][j] != 0)
                    tmp++;

        result = min(result, tmp);

        return;
    }

    for (int i = 1; i <= w; i++)
    {
        if (!selected[cnt])
        {
            selected[cnt] = i;
            selection(cnt + 1);
            selected[cnt] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    int t_num;
    cin >> t_num;

    for (int t = 1; t <= t_num; t++)
    {
        cin >> n >> w >> h;

        result = 1e9;
        memset(real_arr, 0x00, sizeof(real_arr));
        memset(arr, 0x00, sizeof(arr));
        memset(selected, 0x00, sizeof(selected));

        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                cin >> real_arr[i][j];

        selection(0);

        cout << "#" << t << " " << result << '\n';
    }

    return 0;
}