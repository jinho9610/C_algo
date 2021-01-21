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

const int INF = 1e9;
int step[100001], power[5][5], dp[100001][5][5]; // 단계, 왼발위치, 오른발 위치  까지 소모한 최소의 힘

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    power[0][1] = power[0][2] = power[0][3] = power[0][4] = 2;
    power[1][2] = power[1][4] = power[2][1] = power[2][3] = power[3][2] = power[3][4] = power[4][3] = power[4][1] = 3;
    power[1][3] = power[2][4] = power[3][1] = power[4][2] = 4;

    for (int i = 1; i < 5; i++)
        power[i][i] = 1;

    int n = 0;
    while (true)
    {
        cin >> step[n + 1];
        if (step[n + 1] == 0)
            break;
        n++;
    }

    for (int i = 0; i < 100001; i++)
    {
        for (int l = 0; l < 5; l++)
        {
            for (int r = 0; r < 5; r++)
                dp[i][l][r] = INF;
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        // 할일은 <i> 단계의 결과는 잘 끝냈고, <i+1>단계로 가고싶음
        // 내가 밟아야할 DDR 번호는 i+1예정임
        for (int l = 0; l <= 4; l++)
        {
            for (int r = 0; r <= 4; r++)
            {
                //dp[i][l][r] : i 단계일 때 왼발 l 오른발 r일 때 소모한 힘
                // 가장 작은 힘일 때만 넣고 싶음
                // 왼발을 움직여봄 dp[i+1][step[i+1]][r]
                int ddr = step[i + 1], used_power;
                // ddr : 다음 단계에 발이 이동해야할 곳

                used_power = dp[i][l][r] + power[l][ddr];
                if (r != ddr && used_power < dp[i + 1][ddr][r])
                    dp[i + 1][ddr][r] = used_power;

                //오른발 움직여봄
                used_power = dp[i][l][r] + power[r][ddr];       // power[a][b] : 발이 a에서 b로 옮기는 데 소모되는 힘
                if (l != ddr && used_power < dp[i + 1][l][ddr]) // 오른발 옮기려는 곳에 왼발이 있으면 안됨
                    dp[i + 1][l][ddr] = used_power;
            }
        }
    }

    int ans = INF;
    for (int l = 0; l < 5; l++)
        for (int r = 0; r < 5; r++)
            if (dp[n][l][r] < ans)
                ans = dp[n][l][r];

    cout << ans << endl;

    return 0;
}