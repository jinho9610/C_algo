/* BOJ 1749 점수따먹기 */
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

#define endl '\n'

typedef long long ll;

int n, m, arr[201][201], prefix_sum[201][201];
int answer = -10000 * 200 * 200;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    int cur_row_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cur_row_sum = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            cur_row_sum += arr[i][j];
            prefix_sum[i][j] = prefix_sum[i - 1][j] + cur_row_sum;
        }
    }

    for (int i1 = 1; i1 <= n; i1++)
        for (int j1 = 1; j1 <= m; j1++)
            for (int i2 = i1; i2 <= n; i2++)
                for (int j2 = j1; j2 <= m; j2++)
                    answer = max(answer,
                                 prefix_sum[i2][j2] - prefix_sum[i1 - 1][j2] - prefix_sum[i2][j1 - 1] + prefix_sum[i1 - 1][j1 - 1]);

    cout << answer << endl;

    return 0;
}