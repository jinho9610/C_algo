#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, offset_x;
vector<vector<int>> arr;
bool visited[16][16];
int ans = 0;
vector<int> score_log;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void save_arr(vector<vector<int>> &tmp)
{
    for (int i = 1; i <= 3 * n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = arr[i][j];
}

void load_arr(vector<vector<int>> &tmp)
{
    for (int i = 1; i <= 3 * n; i++)
        for (int j = 1; j <= n; j++)
            arr[i][j] = tmp[i][j];
}

void gravity()
{
    for (int j = 1; j <= n; j++)
    {
        for (int i = 3 * n; i >= 2; i--)
        {
            if (arr[i][j] == 0)
            {
                int k;
                for (k = i - 1; k >= 1; k--)
                    if (arr[k][j] != 0)
                        break;

                if (k == 0)
                    continue;

                arr[i][j] = arr[k][j];
                arr[k][j] = 0;
            }
        }
    }
}

int bfs(pair<int, int> p)
{
    vector<pair<int, int>> disapper_lists;
    memset(visited, 0x00, sizeof(visited));

    queue<pair<int, int>> q;
    q.push(p);
    visited[p.first - offset_x][p.second] = true;

    int cnt = 0;
    int max_h = 0, min_h = 0, max_w = 0, min_w = 0;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        disapper_lists.push_back({x, y});

        if (x - p.first > 0)
            max_h = max(max_h, x - p.first);
        else
            min_h = min(min_h, x - p.first);

        if (y - p.second > 0)
            max_w = max(max_w, y - p.second);
        else
            min_w = min(min_w, y - p.second);
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (isInside(nx - offset_x, ny) && !visited[nx - offset_x][ny] && arr[nx][ny] == arr[x][y])
            {
                q.push({nx, ny});
                visited[nx - offset_x][ny] = true;
            }
        }
    }

    for (auto dl : disapper_lists)
        arr[dl.first][dl.second] = 0;

    return cnt + (max_h - min_h + 1) * (max_w - min_w + 1);
}

void dfs(int cnt, int score)
{
    if (cnt == 3)
    {
        ans = max(ans, score);
        return;
    }

    // arr 임시 저장
    vector<vector<int>> tmp;
    tmp.resize(n * 3 + 1);
    for (int i = 0; i <= n * 3 + 1; i++)
        arr[i].resize(n + 1), tmp[i].resize(n + 1);
    save_arr(tmp);

    for (int i = offset_x + 1; i <= 3 * n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int get_score = bfs({i, j});
            score_log.push_back(get_score);
            gravity();
            dfs(cnt + 1, score + get_score);
            load_arr(tmp);
            score_log.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n;
    offset_x = 2 * n;

    arr.resize(n * 3 + 1);
    for (int i = 0; i <= n * 3 + 1; i++)
        arr[i].resize(n + 1);

    for (int i = 1; i <= 3 * n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    // gravity();

    // for (int i = 1; i <= 3 * n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    dfs(0, 0);

    cout << ans << endl;

    return 0;
}