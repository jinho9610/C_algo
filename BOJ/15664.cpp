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
#include <set>

using namespace std;

typedef long long ll;

int n, m, arr[9];
bool selected[9];
vector<int> ans;
set<vector<int>> s;

void dfs(int idx, int depth)
{
    if (depth == m)
    {
        s.insert(ans);
        return;
    }

    for (int i = idx + 1; i <= n; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;
            ans.push_back(arr[i]);
            dfs(i, depth + 1);
            ans.pop_back();
            selected[i] = false;
        }
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

    sort(arr + 1, arr + 1 + n);

    dfs(0, 0);

    for (auto v : s)
    {
        for (auto i : v)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}