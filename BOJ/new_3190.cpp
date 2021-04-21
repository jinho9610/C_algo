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

int n, k, l, arr[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int head_x = 1, head_y = 1;
int tail_x = 1, tail_y = 1;
int dir = 1; // 처음에는 오른쪽 즉, 동쪽을 바라본다.
int t_dir = 1;
vector<pair<int, char>> commands;        // 행동 강령
queue<pair<pair<int, int>, int>> memory; // 머리의 움직임을 기억해두고 꼬리가 참고하기 위한 수단

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= n;
}

bool isMyself(int x, int y)
{
    return arr[x][y] == 1;
}

bool isApple(int x, int y)
{
    return arr[x][y] == 2;
}

void rotate_dir(char d)
{
    if (d == 'D') // 오른쪽으로 90도 회전
        dir = (dir + 1) % 4;
    else // 왼쪽으로 90도 회전
        dir = (dir + 4 - 1) % 4;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 2; //사과는 2로 표시
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        commands.push_back({x, c});
    }

    int sec = 0, command_idx = 0;
    while (true) // 몇초만에 게임이 끝나는 지 확인할 거야
    {
        // 뱀 전진
        int nx = head_x + dx[dir], ny = head_y + dy[dir];
        if (!isInside(nx, ny) || isMyself(nx, ny)) // 벽이랑 부딪히거나 자기 자신이랑 부딪히면
            break;                                 // 게임 종료

        head_x = nx, head_y = ny;     // 머리 위치 업데이트
        if (!isApple(head_x, head_y)) // 사과를 먹지 못했다면 꼬리 움직여야지
        {
            if (tail_x == memory.front().first.first && tail_y == memory.front().first.second)
            {
                t_dir = memory.front().second; // 이 지점에서 머리가 방향을 튼 적이 있으면 꼬리 진행 방향도 업데이트
                memory.pop();
            }
            arr[tail_x][tail_y] = 0; // 원래 있던 칸에서 꼬리 비워주기
            tail_x += dx[t_dir], tail_y += dy[t_dir];
        }
        arr[head_x][head_y] = 1;

        sec++;
        if (sec == commands[command_idx].first)
        {
            rotate_dir(commands[command_idx].second); // 방향 전환하고
            memory.push({{head_x, head_y}, dir});     // (head_x, head_y)에서 머리 방향이 dir로 바꼈으니 꼬리도 여기에 도착하면 방향 바꿔
            command_idx++;                            // 명령 인덱스 하나 증가
        }
    }
    cout << sec + 1 << '\n';

    return 0;
}