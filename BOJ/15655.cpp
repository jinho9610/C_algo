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

int n, m, arr[9], selected[9];
vector<int> ans;

void dfs(int idx, int cnt)
{
    if (cnt == m)
    {
        for (auto a : ans)
            cout << a << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx + 1; i <= n; i++)
    {
        ans.push_back(arr[i]);
        dfs(i, cnt + 1);
        ans.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    dfs(0, 0);

    return 0;
}