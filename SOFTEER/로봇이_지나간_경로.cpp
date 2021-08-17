#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int h, w;
char arr[26][26];
bool visited[26][26];
int dx[] = {-1, 0, 1, 0}; // 북 동 남 서
int dy[] = {0, 1, 0, -1};

string ans;
char looking_dir;
int start_x, start_y;

vector<pair<int, int>> starting_candis;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> h >> w;

    int trace_cnt = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '#')
                trace_cnt++;
        }

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (arr[i][j] == '.')
                continue;
            // 탐색을 시작할 점 찾기
            int cnt = 0;
            for (int k = 0; k < 4; k++)
                if (arr[i + dx[k]][j + dy[k]] == '#')
                    cnt++;

            if (cnt == 1)
                starting_candis.push_back({i, j});
        }
    }

    bool isFirst = true;

    for (auto starting_candi : starting_candis)
    {
        memset(visited, 0x00, sizeof(visited));

        string tmp_ans = "";
        int tmp_looking_dir;
        int tmp_start_x, tmp_start_y;

        int x = starting_candi.first, y = starting_candi.second;
        tmp_start_x = x, tmp_start_y = y;

        // 가장 처음 바라보는 위치 선정
        for (int i = 0; i < 4; i++)
        {
            if (arr[x + dx[i]][y + dy[i]] == '#')
            {
                tmp_looking_dir = i;
                break;
            }
        }

        int cnt = 1;
        while (cnt < trace_cnt)
        {
            int nx = x + dx[tmp_looking_dir], nx2 = x + 2 * dx[tmp_looking_dir];
            int ny = y + dy[tmp_looking_dir], ny2 = y + 2 * dy[tmp_looking_dir];
            if (arr[nx][ny] == '#' && arr[nx2][ny2] == '#' && !visited[nx][ny] && !visited[nx2][ny2]) // 두칸 전진 가능한 경우
            {
                tmp_ans += "A", cnt += 2;
                visited[nx][ny] = true;
                visited[nx2][ny2] = true;
                x = nx2, y = ny2; // 로봇 이동
            }

            else // 전진이 불가능한 경우에는 회전이 필요
            {
                // 어느 방향으로 회전할 것인지 판단 필요
                for (int i = 1; i < 4; i++)
                {
                    int nd = (tmp_looking_dir + i) % 4; // 시계방향 90도 회전
                    if (arr[x + dx[nd]][y + dy[nd]] == '#' && !visited[x + dx[nd]][y + dy[nd]])
                    {
                        if (i == 1)
                            tmp_ans += "R";
                        else if (i == 2)
                            tmp_ans += "RR";
                        else
                            tmp_ans += "L";
                        tmp_looking_dir = nd;

                        break;
                    }
                }
            }
        }

        if (isFirst)
        {
            ans = tmp_ans;
            start_x = tmp_start_x;
            start_y = tmp_start_y;

            if (tmp_looking_dir == 0)
                looking_dir = '^';
            else if (tmp_looking_dir == 1)
                looking_dir = '>';
            else if (tmp_looking_dir == 2)
                looking_dir = '<';
            else
                looking_dir = 'v';

            isFirst = false;
        }

        else if (ans.length() > tmp_ans.length())
        {
            ans = tmp_ans;
            start_x = tmp_start_x;
            start_y = tmp_start_y;

            if (tmp_looking_dir == 0)
                looking_dir = '^';
            else if (tmp_looking_dir == 1)
                looking_dir = '>';
            else if (tmp_looking_dir == 2)
                looking_dir = 'v';
            else
                looking_dir = '<';
        }
    }

    cout << start_x << ' ' << start_y << endl;
    cout << looking_dir << endl;
    cout << ans << endl;

    return 0;
}