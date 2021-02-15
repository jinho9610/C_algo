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

int n, m, arr[9], selected[9]; // 1부터 n까지 자연수 중 중복 없이 m개를 고른 수열
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

    for (int i = 1; i <= n; i++)
    {
        if (!selected[i])
        {
            ans.push_back(arr[i]);
            selected[i] = true;
            dfs(i, cnt + 1);
            selected[i] = false;
            ans.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        arr[i] = i;

    dfs(0, 0);

    return 0;
}