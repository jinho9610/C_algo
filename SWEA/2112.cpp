#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define endl '\n'
#define A 0
#define B 1

int T, w, d, k;
int real_arr[14][21], arr[14][21], selected[14];
bool isSucc = false;
vector<pair<int, int>> opers;

void copy_arr()
{
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= w; j++)
            arr[i][j] = real_arr[i][j];
}

bool inspection()
{
    // 모든 열에 대해서 연속되는 값 k개 등장하는지 파악해야함
    bool flag = true;
    for (int j = 1; j <= w; j++)
    {
        bool col_flag = false;
        for (int i = 1; i <= d - (k - 1); i++)
        {
            bool sub_flag = true;
            for (int z = i; z <= i + (k - 1) - 1; z++)
            {
                if (arr[z][j] != arr[z + 1][j]) // 옆과 비교해서 불일치 발생하면
                {
                    sub_flag = false;
                    continue;
                }
            }
            if (sub_flag)
            {
                col_flag = true;
                break;
            }
        }
        if (!col_flag)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

void injection() // 어느 행에 넣을 것인지
{
    for (auto oper : opers)
    {
        int x = oper.first, type = oper.second;

        for (int j = 1; j <= w; j++)
            arr[x][j] = type; // 한 행에 약을 투입하여 전부 칠해버림
    }
}

void pick(int idx, int cnt, int dst)
{
    if (cnt == dst)
    {
        if (isSucc) // 이미 성공했으면
            return; // 바로 리턴
        // 복사
        copy_arr();
        // 투입
        injection();
        // 검사
        isSucc = inspection();
        return;
    }

    for (int i = idx + 1; i <= d; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;
            for (int j = 0; j < 2; j++)
            {
                if (!isSucc)
                {
                    opers.push_back({i, 0}); // i번째 행에 j(0 또는 1) 타입의 약을 넣겠다.
                    pick(i, cnt + 1, dst);
                    opers.pop_back(); // return 이후 돌아오면 벡터에서 연산 하나 제거
                }
            }
            selected[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        memset(real_arr, 0x00, sizeof(real_arr));
        memset(arr, 0x00, sizeof(arr));
        memset(selected, 0x00, sizeof(selected));
        opers.clear();
        isSucc = false;
        int result = 0;

        cin >> d >> w >> k;

        for (int i = 1; i <= d; i++)
            for (int j = 1; j <= w; j++)
                cin >> real_arr[i][j];

        copy_arr();
        if (inspection() || k == 1)
            cout << "#" << t << ' ' << 0 << '\n';

        else
        {
            for (int i = 2; i <= k; i++)
            {
                isSucc = false;
                opers.clear();
                pick(0, 0, i);
                if (isSucc)
                {
                    result = i;
                    break;
                }
            }
            cout << "#" << t << ' ' << result << '\n';
        }
    }

    return 0;
}