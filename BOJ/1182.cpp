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

int n, s, arr[21], result;
bool selected[21];
vector<int> ans;

void dfs(int idx, int cnt, int sum)
{
    if (cnt > 0 && sum == s)
        result++;

    if (cnt == n)
        return;

    for (int i = idx + 1; i <= n; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;
            dfs(i, cnt + 1, sum + arr[i]);
            selected[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr + 1, arr + n); // 오름차순 정렬

    dfs(0, 0, 0);

    cout << result << endl;

    return 0;
}