// 풀이에 사용된 알고리즘:

#define _CRT_SECURE_NO_WARNINGS

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

int tc, n, income[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> tc;

    for (int t = 1; t <= tc; t++) // testcase
    {
        memset(income, 0x00, sizeof(income));

        cin >> n;
        int sum = 0;
        double avg = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> income[i];
            sum += income[i];
        }
        avg = (double)sum / n;

        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (income[i] <= avg)
                cnt++;

        cout << '#' << t << ' ' << cnt << '\n';
    }

    return 0;
}