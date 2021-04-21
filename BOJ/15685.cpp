#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
bool arr[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void make_dragon(int x, int y, int dir, int g)
{
    vector<pair<int, int>> coords;
    int start_x, start_y; // 시작점 좌표
    int end_x, end_y;     // 끝점 좌표 즉 중심

    for (int i = 0; i <= g; i++)
    {
        if (i == 0) // 0세대 완성
        {
            start_x = x, start_y = y; // 시작점은 변하지 않음
            arr[y][x] = true;
            end_x = x + dx[dir], end_y = y + dy[dir];
            arr[end_y][end_x] = true;
            coords.push_back({y, x});
            coords.push_back({end_y, end_x});
        }

        else // 0세대 이상부터는 회전 필요
        {
            int cx = end_x, cy = end_y;
            int rotation_cnt = coords.size();
            for (int j = 0; j < rotation_cnt; j++)
            {
                pair<int, int> coord = coords[j];
                int cur_y = coord.first, cur_x = coord.second; // 얘가 회전 이후에는 새로운 끝점 되어야함
                int nx = -cur_y + cy + cx, ny = cur_x - cx + cy;
                if (j == 0) // 새로운 끝점 // 다음 회전의 중심이 됨
                    end_x = nx, end_y = ny;
                coords.push_back({ny, nx});
                arr[ny][nx] = true;
            }
        }
    }
}

int check() // 정사각형 찾을거야
{
    int cnt = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1])
                cnt++;

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        make_dragon(x, y, d, g);
    }

    cout << check() << '\n';

    return 0;
}