/* BOJ 17140 이차원 배열과 연산 */

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

int r, c, k, r_cnt = 3, c_cnt = 3;
int arr[101][101], check[101];

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second != p2.second)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

void R_calc()
{
    for (int i = 1; i <= r_cnt; i++) // 행 by 행으로 적용
    {
        memset(check, 0x00, sizeof(check)); // 등장횟수 체크용 배열 초기화

        for (int j = 1; j <= c_cnt; j++)
            if (arr[i][j] != 0)
                check[arr[i][j]]++; // 등장 회수 하나 증가

        vector<pair<int, int>> tmp;
        for (int j = 1; j < 101; j++)
        {
            if (!check[j])
                continue;

            tmp.push_back({j, check[j]});
        }

        sort(tmp.begin(), tmp.end(), cmp);

        c_cnt = max(c_cnt, int(tmp.size()) * 2);

        memset(arr[i], 0x00, sizeof(arr[i]));
        for (int j = 0; j < tmp.size(); j++)
        {
            arr[i][j * 2 + 1] = tmp[j].first;
            arr[i][(j + 1) * 2] = tmp[j].second;
        }
    }
}

void C_calc()
{
    for (int j = 1; j <= c_cnt; j++) // 행 by 행으로 적용
    {
        memset(check, 0x00, sizeof(check)); // 등장횟수 체크용 배열 초기화

        for (int i = 1; i <= r_cnt; i++)
            if (arr[i][j] != 0)     // 0이 등장하면 break
                check[arr[i][j]]++; // 등장 회수 하나 증가

        vector<pair<int, int>> tmp;
        for (int i = 1; i < 101; i++)
        {
            if (!check[i])
                continue;

            tmp.push_back({i, check[i]});
        }

        sort(tmp.begin(), tmp.end(), cmp);

        r_cnt = max(r_cnt, int(tmp.size()) * 2);

        for (int i = 1; i < 101; i++)
            arr[i][j] = 0;

        for (int i = 0; i < tmp.size(); i++)
        {
            arr[i * 2 + 1][j] = tmp[i].first;
            arr[(i + 1) * 2][j] = tmp[i].second;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            cin >> arr[i][j];

    int sec = 0;
    if (arr[r][c] == k)
    {
        cout << 0 << endl;
        return 0;
    }

    while (true)
    {
        sec += 1; // 1초 지날 때 마다 r 또는 c 연산

        if (r_cnt >= c_cnt) // R 연산
            R_calc();
        else
            C_calc();

        if (arr[r][c] == k) // 탈출 조건
            break;

        if (sec == 100) // 100초째에 R, C 연산을 하고도 위 탈출조건을 만족하지못한 경우
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << sec << '\n';

    return 0;
}