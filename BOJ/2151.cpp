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

const int INF = 1e9;
int n, visited[51][51][4]; // i, j, dir - 0: 북  1: 동  2: 남  3: 서
char arr[51][51];
pair<int, int> start, dest;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<pair<int, int>, int>> q;

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= n;
}

void bfs()
{
    for (int i = 0; i < 4; i++)
    {
        q.push({{start.first, start.second}, i});
        visited[start.first][start.second][i] = 0; // 방문처리
    }

    while (!q.empty())
    {
        int x = q.front().first.first, y = q.front().first.second;
        int dir = q.front().second;
        q.pop();

        int nx = x + dx[dir], ny = y + dy[dir]; // 기존 방향대로 전진

        if (isInside(nx, ny)) // 벽 내부에 있고
        {
            if (arr[nx][ny] == '.') // 빈곳이라면
            {
                if (visited[nx][ny][dir] > visited[x][y][dir])
                {
                    visited[nx][ny][dir] = visited[x][y][dir];
                    q.push({{nx, ny}, dir});
                }
            }
            else if (arr[nx][ny] == '*')
                continue;                // 벽이라면
            else if (arr[nx][ny] == '!') // 거울을 설치할 수 있는 곳이라면
            {
                if (visited[nx][ny][dir] > visited[x][y][dir]) // 거울을 설치하지 않는 경우
                {
                    visited[nx][ny][dir] = visited[x][y][dir];
                    q.push({{nx, ny}, dir});
                }

                if (!(dir % 2)) // dir == 0 || dir == 2
                {
                    if (visited[nx][ny][1] > visited[x][y][dir] + 1)
                    {
                        visited[nx][ny][1] = visited[x][y][dir] + 1;
                        q.push({{nx, ny}, 1});
                    }
                    if (visited[nx][ny][3] > visited[x][y][dir] + 1)
                    {
                        visited[nx][ny][3] = visited[x][y][dir] + 1;
                        q.push({{nx, ny}, 3});
                    }
                }
                else
                {
                    if (visited[nx][ny][0] > visited[x][y][dir] + 1)
                    {
                        visited[nx][ny][0] = visited[x][y][dir] + 1;
                        q.push({{nx, ny}, 0});
                    }
                    if (visited[nx][ny][2] > visited[x][y][dir] + 1)
                    {
                        visited[nx][ny][2] = visited[x][y][dir] + 1;
                        q.push({{nx, ny}, 2});
                    }
                }
            }
            else if (arr[nx][ny] == '#')
            {
                if (visited[nx][ny][dir] > visited[x][y][dir])
                    visited[nx][ny][dir] = visited[x][y][dir];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) // 맵 정보 입력 받기
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '#')
            {
                if (tmp == 0)
                {
                    start = {i, j}; // 시작 문
                    tmp++;
                }
                else
                    dest = {i, j}; // 목적지 문
            }
            visited[i][j][0] = visited[i][j][1] = visited[i][j][2] = visited[i][j][3] = INF; // visited 배열 초기화, 최종적으로 min 값을 찾아야하므로 INF로 초기화
        }
    }

    bfs();

    int min_val = INF;
    for (int i = 0; i < 4; i++)
        min_val = min(min_val, visited[dest.first][dest.second][i]);

    cout << min_val << '\n';

    return 0;
}