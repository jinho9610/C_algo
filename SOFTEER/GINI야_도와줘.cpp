/* */
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

#define endl '\n'

typedef long long ll;

int r, c;
char arr[51][51];
queue<pair<int, int>> q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isInside(int x, int y)
{
    return 1 <= x && x <= r && 1 <= y && y <= c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    vector<pair<int, int>> waters;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'W') // 태범이의 움직임이 소나기의 움직임보다 선행되어야함
                q.push({i, j});
            else if (arr[i][j] == '*') // 따라서 소나기의 위치는 임시 버퍼에 넣어두었다가,
                waters.push_back({i, j});
        }
    }
    for (auto water : waters) // 태범이가 들어가 있는 큐에 소나기 위치도 넣어줌
        q.push(water);

    int minute = 0;
    while (!q.empty())
    {
        minute++;
        int q_size = q.size();

        while (q_size--)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (arr[x][y] == '*') // 소나기인 경우
                {
                    // 태범이 집이나 강으로는 소나기 침범X
                    if (arr[nx][ny] == 'H' || arr[nx][ny] == 'X')
                        continue;

                    if (isInside(nx, ny) && (arr[nx][ny] == '.' || arr[nx][ny] == 'W'))
                    {
                        q.push({nx, ny});
                        arr[nx][ny] = '*';
                    }
                }
                else if (arr[x][y] == 'W') // 태범이인 경우
                {
                    // 소나기나 강으로는 태범이 지나가지 못함
                    if (arr[nx][ny] == '*' || arr[nx][ny] == 'X')
                        continue;

                    else if (arr[nx][ny] == 'H') // 집인 경우
                    {
                        cout << minute << endl;
                        return 0;
                    }

                    if (isInside(nx, ny) && arr[nx][ny] == '.')
                    {
                        q.push({nx, ny});
                        arr[nx][ny] = 'W';
                    }
                }
            }
        }
    }

    cout << "FAIL" << endl;

    return 0;
}