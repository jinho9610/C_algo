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

int n, k, l;
int arr[101][101];
char commands[10001];
// 처음에는 동쪽을 향함
int head_d = 1, tail_d = 1, len = 1; // 각각 머리와 꼬리의 진행 방향, 뱀의몸길이
int head_x = 1, head_y = 1;
int tail_x = 1, tail_y = 1;
int dx[] = {-1, 0, 1, 0}; // 북 동 남 서
int dy[] = {0, 1, 0, -1}; // 북 동 남 서
char c;
queue<pair<pair<int, int>, int>> q;

bool isFinished(int x, int y) // 전진하려는 곳이 게임 종료 조건에 부합하는지 확인
{
    if (x < 1 || x > n || y < 1 || y > n || arr[x][y] == 5)
        return true; // 벽에 부딪히거나 내 몸통과 만나면
    else
        return false;
}

void change_dir(char d)
{
    // cur_d는 현재 방향, char d는 L 또는 D
    // cur_d 가 0이면 북쪽, 1이면
    if (head_d == 0) // 머리가 북쪽으로 가던 중
    {
        if (d == 'L')
            head_d = 3; // 서쪽으로 방향 변경
        else
            head_d = 1; // 동쪽으로 방향 변경
    }
    else if (head_d == 1) // 머리가 동쪽으로 가던 중
    {
        if (d == 'L')
            head_d = 0; // 북쪽으로 방향 변경
        else
            head_d = 2; // 남쪽으로 방향 변경
    }
    else if (head_d == 2) // 머리가 남쪽으로 가던 중
    {
        if (d == 'L')
            head_d = 1; // 동쪽으로 방향 변경
        else
            head_d = 3; // 서쪽으로 방향 변경
    }
    else // 머리가 서쪽으로 가던 중
    {
        if (d == 'L')
            head_d = 2; // 남쪽으로 방향 변경
        else
            head_d = 0; // 북쪽으로 방향 변경
    }
    // 몸 길이가 1보다 긴 경우에는 꼬리 방향의 변화는 없음
    if (len == 1)
        tail_d = head_d; // 뱀 길이가 1인 경우에는 머리 방향이 곧 꼬리 방향
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1; // 사과는 1로 표시
    }
    arr[1][1] = 5; // 뱀이 있는 곳은 5로 표시

    cin >> l;

    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        commands[x] = c; // x초의 명령을 배열에 저장 x초와 idx는 동일함
    }                    // 여기까지 모든 입력 종료

    int second = 0;
    while (true)
    {
        int nx = head_x + dx[head_d];
        int ny = head_y + dy[head_d]; // 머리가 전진할 위치

        if (isFinished(nx, ny)) // 종료조건에 부합하면 게임 종료
        {
            cout << second + 1 << '\n';
            return 0;
        }

        if (arr[nx][ny] == 1) // 다음 갈 곳에 사과가 놓여 있는 경우
        {
            len++;       // 몸길이 하나 증가
            head_x = nx; // 머리 이동
            head_y = ny;
            arr[head_x][head_y] = 5;
            // 꼬리는 움직이지 않음
        }
        else if (arr[nx][ny] == 0)
        {
            head_x = nx; // 머리 이동
            head_y = ny;
            arr[head_x][head_y] = 5; // 뱀 머리가 전진한 곳 5로 만든다.
            arr[tail_x][tail_y] = 0; // 원래 꼬리가 있던 곳 빈 곳으로 만들고
            if (tail_x == q.front().first.first && tail_y == q.front().first.second)
            {
                tail_d = q.front().second;
                q.pop();
            }
            tail_x += dx[tail_d];
            tail_y += dy[tail_d]; // 꼬리도 이동
        }

        second++;

        if (commands[second] != 0) // 어떤 명령이 있다면
        {
            char new_d = commands[second];
            change_dir(new_d); // 방향 전환
            q.push({{head_x, head_y}, head_d});
        }
    }

    return 0;
}