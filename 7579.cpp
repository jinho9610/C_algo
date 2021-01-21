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

int n, m, memory[101], cost[101], result;
int dp[101][10001]; // [j][i] 내가 j까지 app을 대상으로 살펴봤을 때, cost i로 얻을 수 있는 최대 메모리 크기

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> memory[i];
    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    for (int j = 1; j <= 100; j++)
    {
        for (int i = 0; i <= 10000; i++)
        {
            // [j][i] : j번째 앱까지 중, cost i로 확보할수 있는 최대 메모리
            dp[j][i] = dp[j - 1][i]; // j번째 앱을 사용하지 않을 때

            if (i - cost[j] >= 0) // j번째 앱을 사용할 때
                dp[j][i] = max(dp[j][i], dp[j - 1][i - cost[j]] + memory[j]);
        }
    }

    // 답 도출

    for (int i = 0; i <= 10000; i++)
    {
        // 비용찾아가면서, m 이상의 메모리 확보했는 지 확인
        if (dp[n][i] >= m)
        {
            result = i;
            break;
        }
    }
    cout << result << '\n';

    return 0;
}