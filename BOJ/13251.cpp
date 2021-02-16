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

int n, m, k, arr[51], tmp;
vector<int> stone_set;

void dfs(int idx, int cnt, int among)
{
    if (cnt == k)
    {
        tmp++;
        return;
    }

    for (int i = idx + 1; i <= among; i++)
        dfs(i, cnt + 1, among);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(arr, arr + 51, 1);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        n += a;
        stone_set.push_back(a);
    }

    cin >> k;

    ll result = 0;
    for (int i = 0; i < m; i++)
    {
        if (stone_set[i] >= k)
        {
            tmp = 0;
            dfs(0, 0, stone_set[i]);
            result += tmp;
        }
    }

    // 전체 돌 n개 중 k개를 뽑는 경우의 수
    tmp = 0;
    dfs(0, 0, n);
    cout << fixed;
    cout.precision(15);
    cout << (double)result / (double)tmp << endl;

    return 0;
}