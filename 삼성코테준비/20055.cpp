#include <iostream>
#include <deque>

using namespace std;

int n, k;

bool isRobot[100]; // 0 ~ n-1에 로봇 위치하고 있는지 파악
deque<int> hp;

// 벨트 회전 함수 // 시계 방향 회전
void belt() // 벨트가 회전하면서 isRobot도 회전해야함
{
    int tmp = hp.back();
    hp.pop_back();
    hp.push_front(tmp);

    for (int i = n - 1; i > 0; i--)
        isRobot[i] = isRobot[i - 1];
    isRobot[0] = false;

    if (isRobot[n - 1])
        isRobot[n - 1] = false; // 회전 이후 내려가는 자리에 로봇이 있다면 로봇 내려
}

// 1~n-2에 위치한 로봇을 한칸 오른쪽으로 움직이는 함수
void move_robots()
{
    // 이동하려는 칸 내구도가 0이면 이동못해
    for (int i = n - 2; i >= 0; i--)
    {
        // 현재 칸에는 로봇이 있는데
        // 오른쪽 칸에는 로봇이 없으며
        // 오른쪽 칸의 내구도가 0이 아닌 경우에는
        // 로봇을 한 칸 이동한다.
        if (isRobot[i] && hp[i + 1] > 0 && !isRobot[i + 1]) // 0이 아니고 로봇이 올라와있지않다면
        {
            isRobot[i] = false;
            isRobot[i + 1] = true;
            hp[i + 1]--; // 이동했으니까 내구도 1 감소
        }
    }
    if (isRobot[n - 1]) // 로봇들의 이동 후 내려가는 칸에 로봇이 있다면 내려보냄
        isRobot[n - 1] = false;
}

int check() // 내구도가 0인 모든 칸 체크하는 함수
{
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++)
        if (hp[i] == 0)
            cnt++;

    return cnt;
}

void print_hp()
{
    for (int i = 0; i < 2 * n; i++)
    {
        cout << hp[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (isRobot[i])
            cout << "O" << ' ';
        else
            cout << "X" << ' ';
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++)
    {
        int a;
        cin >> a;
        hp.push_back(a);
    }

    int stage = 0;
    while (true)
    {
        stage++;
        belt();                       // 한 칸 돌리고 내려가는 위치의 로봇은 내림
        move_robots();                // 로봇들 한칸씩 이동가능하면 이동하고, 내려가는 위치의 로봇은 내림
        if (hp[0] > 0 && !isRobot[0]) // 올라가는 칸에 로봇없다면 하나 올려
        {
            isRobot[0] = true;
            hp[0]--;
        }

        if (check() >= k)
            break;
    }

    cout << stage << '\n';

    return 0;
}