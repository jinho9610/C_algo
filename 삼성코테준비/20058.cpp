// 50분 정도 걸림
#include <iostream>
#include <cmath>
#include <queue>

#define endl '\n'

using namespace std;

typedef long long ll;

int n, q, arr[65][65];
bool visited[65][65];
int side_len;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> stages;

bool isInside(int x, int y)
{
    return 1 <= x && x <= side_len && 1 <= y && y <= side_len;
}

void partial_rotation(int x, int y, int s) // s는 부분 구역의 한변의 길이
{
    vector<int> tmp;

    for (int j = y; j <= y + s - 1; j++)
        for (int i = x; i <= x + s - 1; i++)
            tmp.push_back(arr[i][j]);

    int k = tmp.size() - 1;
    for (int i = x + s - 1; i >= x; i--)
    {
        for (int j = y; j <= y + s - 1; j++)
        {
            arr[i][j] = tmp[k--];
        }
    }
}

void fire_storm(int l)
{
    // 2^l씩 격자 자르기
    int sub_len = pow(2, l);
    for (int i = 1; i < side_len; i += sub_len)
    {
        for (int j = 1; j < side_len; j += sub_len)
        {
            partial_rotation(i, j, sub_len);
        }
    }
}

int getTotalIce() // 남아있는 전체 얼음 양 확인 메소드
{
    int total = 0;
    for (int i = 1; i <= side_len; i++)
        for (int j = 1; j <= side_len; j++)
            if (arr[i][j] > 0)
                total += arr[i][j];

    return total;
}

void check_ice()
{
    vector<pair<int, int>> targets;
    for (int i = 1; i <= side_len; i++)
    {
        for (int j = 1; j <= side_len; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (isInside(nx, ny) && arr[nx][ny] != 0)
                    cnt++;
            }
            if (cnt < 3)
                targets.push_back({i, j});
        }
    }
    for (auto target : targets)
        if (arr[target.first][target.second] != 0)
            arr[target.first][target.second]--;
}

int bfs(pair<int, int> p1) // 얼음 덩어리 중 가장 큰 덩어리 찾기 위한 메소드
{
    int cnt = 0;

    queue<pair<int, int>> q;
    visited[p1.first][p1.second] = true;
    q.push(p1);

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (isInside(nx, ny) && arr[nx][ny] > 0 && !visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("s_input.txt", "r", stdin);

    cin >> n >> q;

    side_len = pow(2, n);

    for (int i = 1; i <= side_len; i++)
        for (int j = 1; j <= side_len; j++)
            cin >> arr[i][j];

    for (int i = 0; i < q; i++)
    {
        int l;
        cin >> l;
        fire_storm(l);
        check_ice();
    }
    cout << getTotalIce() << '\n';

    int max_ice = 0;
    for (int i = 1; i <= side_len; i++)
        for (int j = 1; j <= side_len; j++)
            if (!visited[i][j] && arr[i][j] != 0)
                max_ice = max(max_ice, bfs({i, j}));

    cout << max_ice << '\n';

    return 0;
}
