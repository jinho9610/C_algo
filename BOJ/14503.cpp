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

int n, m, arr[50][50], visited[50][50];
int r, c, dir, cnt = 1;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isInside(int x, int y)
{
    return 0 < x && x < n - 1 && 0 < y && y < m - 1;
}

void change_dir() // 왼쪽으로 방향 돈다
{
    dir = (dir + 3) % 4;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    cin >> r >> c >> dir;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    visited[r][c] = true;
    while (true)
    {
        bool isMoved = false;

        for (int i = 0; i < 4; i++)
        {
            change_dir();
            int nr = r + dx[dir], nc = c + dy[dir];                       // 전진한다면
            if (!visited[nr][nc] && arr[nr][nc] == 0 && isInside(nr, nc)) // 방문한적없고 맵 안이라면
            {                                                             // 로봇 위치 업데이트 및 움직였다고 flag 변경
                r = nr, c = nc;
                visited[r][c] = true; // 방문처리
                cnt++;                // 청소한 곳 개수 증가
                isMoved = true;
                break;
            }
        }

        if (!isMoved) // 네 방향을 다 탐색했음에도 움직임이 없는 경우
        {             // 네 방향 모두 청소되어 있거나 벽인 경우
            int nr = r - dx[dir], nc = c - dy[dir];
            if (arr[nr][nc] == 0 && isInside(nr, nc))
                r = nr, c = nc; // 방향 유지하며 뒤로 한칸 후진
            else                // 후진도 불가능하다면
                break;          // 청소 종료
        }
    }

    cout << cnt << endl;

    return 0;
}