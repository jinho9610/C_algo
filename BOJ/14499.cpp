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

int n, m, x, y, k, arr[20][20];
int commands[1001];
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
int t = 0, d = 0, f = 0, b = 0, l = 0, r = 0;

bool isInside(int x, int y)
{
    return -1 < x && x < n && -1 < y && y < m;
}

void move_dice(int dir)
{
    if (dir == 1) // 오른쪽으로 굴리는 경우
    {
        int tmp = d;
        d = r;
        r = t;
        t = l;
        l = tmp;
    }

    else if (dir == 2) // 왼쪽으로 굴리는 경우
    {
        int tmp = l;
        l = t;
        t = r;
        r = d;
        d = tmp;
    }

    else if (dir == 3) // 위로 굴리는 경우
    {
        int tmp = b;
        b = t;
        t = f;
        f = d;
        d = tmp;
    }

    else if (dir == 4)
    {
        int tmp = d;
        d = f;
        f = t;
        t = b;
        b = tmp;
    }
}

void print_dice()
{
    cout << "top: " << t << "  ";
    cout << "down: " << d << "  ";
    cout << "front: " << f << "  ";
    cout << "back: " << b << "  ";
    cout << "left: " << l << "  ";
    cout << "right: " << r << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < k; i++) // 명령 입력
        cin >> commands[i];

    for (int i = 0; i < k; i++)
    {
        int comm = commands[i];

        int nx = x + dx[comm];
        int ny = y + dy[comm];

        if (!isInside(nx, ny)) // 명령 무시하고, 출력도 하지 않는다. 바로 다음 명령처리
            continue;

        move_dice(comm); // 주사위 굴림
        x = nx, y = ny;

        // 현재 맵 바닥 확인해야함
        if (!arr[x][y])
            arr[x][y] = d;

        else
        {
            d = arr[x][y];
            arr[x][y] = 0;
        }
        // print_dice();

        cout << t << '\n';
    }

    return 0;
}