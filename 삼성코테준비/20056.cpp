#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

typedef long long ll;

int n, mm, k;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<pair<int, int>, int>> arr[51][51];

void move_fbs() // fb들의 이동
{
    vector<pair<pair<int, int>, int>> tmp[51][51]; // 이동 후 위치를 저장한 임시 위치
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (auto fb : arr[i][j])
            {
                int m = fb.first.first, d = fb.first.second, s = fb.second;
                int move = s % n;
                int nx = i + dx[d] * move, ny = j + dy[d] * move;
                if (nx > n)
                    nx -= n;
                if (ny > n)
                    ny -= n;
                if (nx < 1)
                    nx += n;
                if (ny < 1)
                    ny += n;

                tmp[nx][ny].push_back({{m, d}, s});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j].clear();
            for (auto fb : tmp[i][j])
                arr[i][j].push_back({{fb.first.first, fb.first.second}, fb.second});
        }
    }
}

bool isAllOdd(vector<int> &vv)
{
    bool flag = true;
    for (int v : vv)
    {
        if (v % 2 != 1)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool isAllEven(vector<int> &vv)
{
    bool flag = true;
    for (int v : vv)
    {
        if (v % 2 != 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void sigma_fbs()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j].size() >= 2) // 같은 칸에 두개 이상의 파이어볼이 있는 경우
            {                          // 합친 후 새로운, 질량, 방향
                // 질량이 0이면 없애버림
                int nm = 0, nd = 0, ns = 0, cnt = 0;
                vector<int> dd;
                for (auto fb : arr[i][j])
                {
                    cnt++;
                    nm += fb.first.first;
                    ns += fb.second;
                    dd.push_back(fb.first.second);
                }
                nm /= 5, ns /= cnt;

                arr[i][j].clear(); // 기존에 있던 파이어볼 삭제

                if (nm != 0) // 새로운 파이어볼 질량 0이면 걍 없애버림
                {
                    if (isAllOdd(dd) || isAllEven(dd))
                    {
                        arr[i][j].push_back({{nm, 0}, ns});
                        arr[i][j].push_back({{nm, 2}, ns});
                        arr[i][j].push_back({{nm, 4}, ns});
                        arr[i][j].push_back({{nm, 6}, ns});
                    }
                    else
                    {
                        arr[i][j].push_back({{nm, 1}, ns});
                        arr[i][j].push_back({{nm, 3}, ns});
                        arr[i][j].push_back({{nm, 5}, ns});
                        arr[i][j].push_back({{nm, 7}, ns});
                    }
                }
            }
        }
    }
}

void print_fbs() // 현재 fireball 상태들 출력하는 함수
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (auto fb : arr[i][j])
                cout << i << ' ' << j << ' ' << fb.first.first << ' ' << fb.first.second << ' ' << fb.second << endl;
        }
    }
}

int check()
{
    int total = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (auto fb : arr[i][j])
                total += fb.first.first;

    return total;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("s_input.txt", "r", stdin);
    cin >> n >> mm >> k;

    for (int i = 0; i < mm; i++)
    {
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        arr[x][y].push_back({{m, d}, s});
        // x,y에 질량 m, 방향 d, 속도 s인
    }

    for (int i = 0; i < k; i++)
    {
        move_fbs();
        sigma_fbs();
    }

    cout << check() << endl;

    return 0;
}