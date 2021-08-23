#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<pair<int, int>> starting_candis;

int h, w;
char arr[26][26];
int start_x, start_y, dest_x, dest_y;
int ld; // looking_dir
char init_ld;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0}; // 동 남 서 북

bool isInside(int x, int y)
{
    return 1 <= x && x <= h && 1 <= y && y <= w;
}

void find_start_point()
{
    bool found = false;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (arr[i][j] == '.')
                continue;

            int cnt = 0, tmp_k = 0;
            for (int k = 0; k < 4; k++)
                if (isInside(i + dx[k], j + dy[k]) && arr[i + dx[k]][j + dy[k]] == '#')
                    tmp_k = k, cnt++;

            if (cnt == 1)
            {
                if (!found)
                {
                    start_x = i, start_y = j;
                    ld = tmp_k;
                    found = true;
                }
                else
                    dest_x = i, dest_y = j;
            }
        }
    }
    if (ld == 0)
        init_ld = '>';
    else if (ld == 1)
        init_ld = 'v';
    else if (ld == 2)
        init_ld = '<';
    else
        init_ld = '^';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> h >> w;

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> arr[i][j];

    // 시작 위치 후보 찾기
    find_start_point();

    // 명령어 셋 만들기 시작
    bool visited[26][26];
    visited[start_x][start_y] = true;

    int x = start_x, y = start_y;
    string ans = "";
    while (!(x == dest_x && y == dest_y))
    {
        //cout << "현재 위치 : {" << x << ", " << y << "} 현재 바라보는 방향 : " << ld << endl;
        int nx1 = x + dx[ld], ny1 = y + dy[ld];
        int nx2 = x + 2 * dx[ld], ny2 = y + 2 * dy[ld];
        if (arr[nx1][ny1] == '#' && arr[nx2][ny2] == '#')
        {
            x = nx2, y = ny2;
            visited[nx1][ny1] = true;
            visited[nx2][ny2] = true;
            ans += "A";
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                int nd;
                bool is_R = true;
                if (i == 0) // 시계방향 90도 회전, R
                {
                    is_R = true;
                    nd = (ld + 1 + 4) % 4;
                }
                else // 반시계방향 90도 회전, L
                {
                    is_R = false;
                    nd = (ld - 1 + 4) % 4;
                }

                int nx = x + dx[nd], ny = y + dy[nd];
                if (arr[nx][ny] == '#')
                {
                    //cout << "기존 ld: " << ld << "  새로운 nd: " << nd << endl;
                    ld = nd;
                    if (is_R)
                        ans += "R";
                    else
                        ans += "L";
                    break;
                }
            }
        }
    }
    cout << start_x << ' ' << start_y << endl;
    cout << init_ld << endl;
    cout << ans << endl;

    return 0;
}