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

int r, c, t, arr[51][51], temp[51][51];
pair<int, int> machine[2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y)
{
    return 0 < x && x <= r && 0 < y && y <= c;
}

void diffuse() // 미세먼지 확장
{
    memset(temp, 0x00, sizeof(temp));

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] > 0) // 먼지가 있는 칸이라면
            {
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (isInside(nx, ny) && arr[nx][ny] != -1)
                        cnt++;
                }

                int amt = arr[i][j] / 5; // 확산되는 양
                arr[i][j] -= cnt * amt;  // 확산되고 남는 양

                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (isInside(nx, ny) && arr[nx][ny] != -1)
                        temp[nx][ny] += amt;
                }
            }
        }
    }

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            arr[i][j] += temp[i][j];
}

void wind() // 공기청정기 바람으로 인한 미세먼지 이동
{
    // 윗 공기청정기
    for (int i = machine[0].first - 1; i > 0; i--)
        arr[i][1] = arr[i - 1][1];

    for (int i = 1; i <= c - 1; i++)
        arr[1][i] = arr[1][i + 1];

    for (int i = 1; i <= machine[0].first - 1; i++)
        arr[i][c] = arr[i + 1][c];

    for (int i = c; i >= 3; i--)
        arr[machine[0].first][i] = arr[machine[0].first][i - 1];

    arr[machine[0].first][2] = 0;

    // 아랫 공기 청정기

    for (int i = machine[1].first + 1; i <= r; i++)
        arr[i][1] = arr[i + 1][1];

    for (int i = 1; i <= c - 1; i++)
        arr[r][i] = arr[r][i + 1];

    for (int i = r; i > machine[1].first; i--)
        arr[i][c] = arr[i - 1][c];

    for (int i = c; i >= 3; i--)
        arr[machine[1].first][i] = arr[machine[1].first][i - 1];

    arr[machine[1].first][2] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> r >> c >> t;

    bool flag = false;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
            if (!flag && arr[i][j] == -1)
            {
                machine[0] = {i, j}; // 윗 공기청정기 좌표
                flag = true;
            }
            if (flag && arr[i][j] == -1)
                machine[1] = {i, j}; // 아랫 공기청정기 좌표
        }
    }

    int s = 0;
    while (true)
    {
        diffuse();
        wind();
        s++;

        if (s == t)
            break;
    }

    int result = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] != -1)
                result += arr[i][j];
        }
    }

    cout << result << '\n';

    return 0;
}