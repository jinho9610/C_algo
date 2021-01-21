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

int n;
pair<int, int> matrix[501];
ll dp[501][501];

ll calc(int start, int end) // 행렬 s부터 행렬 e까지 계산했을 때 연산 횟수의 최솟값
{
    if (end - start == 1)
        return dp[start][end] = matrix[start].first * matrix[start].second * matrix[end].second;

    if (start == end)
        return 0;

    if (dp[start][end])
        return dp[start][end];

    ll mn = -1;
    for (int mid = start; mid < end; mid++)
    {
        ll tmp = calc(start, mid) + calc(mid + 1, end) + matrix[start].first * matrix[mid].second * matrix[end].second;
        if (mn == -1 || tmp < mn)
            mn = tmp;
    }

    return dp[start][end] = mn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int r, c;
        cin >> r >> c;
        matrix[i].first = r, matrix[i].second = c;
    }

    cout << calc(1, n) << '\n';

    return 0;
}