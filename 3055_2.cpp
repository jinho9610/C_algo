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

int r, c;
char arr[50][50];
int visited[50][50];
queue<pair<int, int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs()
{
    ll result = 0;
    while (!q.empty())
    {
        // 1. 큐에서 꺼내옴
        int x = q.front().first;
        int y = q.front().second;
        char type = arr[x][y];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 2. 목적지에 도달했는가
            if (type == 'S' && arr[nx][ny] == 'D') // 방금 큐에서 나온 놈이 고슴도치이고 다음에 도착한 곳이 비버 굴이면
                return visited[x][y];

            // 3. 연결된 곳을 순회
            // 4. 갈 수 있는가?
            if (type == '*' && visited[nx][ny] < 2 && arr[nx][ny] == '.' && -1 < nx && nx < r && -1 < ny && ny < c) // 물 움직임
            {
                visited[nx][ny] = visited[x][y] + 1; // 5. 체크인 & 큐에 넣음
                arr[nx][ny] = '*';
                q.push(make_pair(nx, ny));
            }
            if (type == 'S' && !visited[nx][ny] && arr[nx][ny] == '.' && -1 < nx && nx < r && -1 < ny && ny < c) // 고슴도치 움직임
            {
                visited[nx][ny] = visited[x][y] + 1; // 5. 체크인 & 큐에 넣음
                arr[nx][ny] = 'S';
                arr[x][y] = '.';
                q.push(make_pair(nx, ny));
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    // 보드 만들기
    pair<int, int> tmp;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                tmp = make_pair(i, j); // 일단 임시 저장
                visited[i][j] = 1;
            }
            if (arr[i][j] == '*')
            {
                q.push(make_pair(i, j)); // 물부터 큐에 다 넣고
                visited[i][j] = 1;
            }
        }
    }
    q.push(tmp); // 고슴도치 위치 큐에 넣는다

    ll ans = bfs();
    if (ans == -1)
        cout << "KAKTUS" << '\n';
    else
        cout << ans << '\n';

    return 0;
}