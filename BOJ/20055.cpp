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

bool robot[101];
int n, k, cnt, stage, arr[201];
int u_pos = 1, d_pos = n;

void rotate() // 로봇의 위치와 벨트(내구도)도 함께 회전
{
    bool tmp = robot[n];
    for (int i = n; i > 1; i--)
        robot[i] = robot[i - 1];
    robot[1] = false; // 첫번째칸에는 무조건 로봇없는 상태

    robot[n] = false; // 내려가는 위치에 있는 로봇은 무조건 내려간다

    int ntmp = arr[n * 2]; // 벨트는 빙글빙글 돈다
    for (int i = 2 * n; i > 1; i--)
        arr[i] = arr[i - 1];
    arr[1] = ntmp;
}

void robot_move()
{
    for (int i = n - 1; i > 0; i--) // 어짜피 n번에 위치한 로봇은 내려갔을 것이므로 고려하지 않아도 됨
    {
        if (robot[i] && !robot[i + 1] && arr[i + 1]) // 현재 칸에 로봇이 있고, 다음 칸에 로봇이 없고, 다음 칸 내구도가 남아있다면
        {
            robot[i] = false;
            robot[i + 1] = true; // 다음칸으로 로봇 이동
            arr[i + 1]--;        // 내구도 1감소

            if (!arr[i + 1]) // 방금 로봇이 이동한 칸 내구도가 0이 되었다면
                cnt++;
        }
    }
    robot[n] = false; // 내려가는 곳 로봇은 무조건 내려간다
}

void robot_up()
{
    if (arr[1]) // 1번칸 내구도가 0이 아니라면
    {
        robot[1] = true; // 1번칸에 로봇 올라가고
        arr[1]--;        // 1번칸 내구도 감소시키고
        if (!arr[1])     // 1번칸 내구도가 0이라면
            cnt++;       // 내구도가 0인 칸 개수 하나 증가
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= 2 * n; i++)
        cin >> arr[i];

    while (true)
    {
        stage++;

        //  1. 벨트가 한 칸 회전한다.
        rotate();
        if (k <= cnt)
            break;

        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동
        robot_move();
        if (k <= cnt)
            break;

        if (!robot[1]) // 올라가는 칸에 로봇이 없다면
        {
            robot_up();
            if (k <= cnt)
                break;
        }
    }

    cout << stage << '\n';

    return 0;
}