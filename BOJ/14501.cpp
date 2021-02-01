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

int n, t[16], p[16], visited[16];

typedef long long ll;

int dfs(int idx)
{
    int sum = p[idx];

    if (idx + t[idx] > n + 1)
        return 0;

    for (int i = idx + t[idx]; i <= n; i++)
        sum = max(sum, p[idx] + dfs(i));

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        t[i] = a, p[i] = b;
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
        result = max(result, dfs(i));

    cout << result << endl;

    return 0;
}