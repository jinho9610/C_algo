/* BOJ 2253 점프 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int INF = 1e9;
int n, m;
bool cant_step_on[10010];
map<int, vector<int>> dp;

int dfs(int pos, int jump)
{
    if (pos > n)
        return -1; // 불가능한 경우의 수
    if (pos == n)
        return 1;
    if (cant_step_on[pos])
        return -1;

    if (dp.count(jump) == 0)
        dp[jump] = vector<int>(n + 1, 0);

    if (dp[jump][pos] != 0)
        return dp[jump][pos];
    if (jump == 0)
        return -1;

    int Min = INF;
    int next_jumps[3] = {jump - 1, jump, jump + 1};
    for (int next_jump : next_jumps)
    {
        int tmp = dfs(pos + next_jump, next_jump);
        if (tmp != -1)
            Min = min(Min, tmp);
    }
    if (Min != INF)
        return dp[jump][pos] = Min + 1;
    else
        return dp[jump][pos] = -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    int a;
    while (m--)
    {
        cin >> a;
        cant_step_on[a] = true; // 나보다 작은 돌이므로 올라설 수 없음
    }

    cout << dfs(2, 1) << endl;

    return 0;
}