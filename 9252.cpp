// 풀이에 사용된 알고리즘: dp, tracking기법

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
string s1, s2;
int dp[1001][1001];
pair<pair<int, int>, char> tracking[1001][1001]; // i, j, c

int calc(int idx1, int idx2)
{
    if (idx1 < 0 || idx2 < 0)
        return 0;

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (s1[idx1] == s2[idx2])
    {
        tracking[idx1][idx2].first.first = idx1 - 1;
        tracking[idx1][idx2].first.second = idx2 - 1;
        tracking[idx1][idx2].second = s1[idx1];
        return dp[idx1][idx2] = calc(idx1 - 1, idx2 - 1) + 1;
    }

    //다른 경우
    int tmp1 = calc(idx1 - 1, idx2); // s1의 문자를 하나 배제한 경우의 수
    int tmp2 = calc(idx1, idx2 - 1); // s2의 문자를 하나 배제한 경우의 수
    if (tmp1 > tmp2)
    {
        tracking[idx1][idx2].first.first = idx1 - 1;
        tracking[idx1][idx2].first.second = idx2;
        return dp[idx1][idx2] = tmp1;
    }
    else
    {
        tracking[idx1][idx2].first.first = idx1;
        tracking[idx1][idx2].first.second = idx2 - 1;
        return dp[idx1][idx2] = tmp2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, 0xff, sizeof(dp));

    cin >> s1 >> s2;
    int len1 = s1.size();
    int len2 = s2.size();

    int result = calc(len1 - 1, len2 - 1);
    cout << result << '\n';

    int cnt = 0, i = len1 - 1, j = len2 - 1;
    vector<char> ans;
    while (cnt != result)
    {
        if (tracking[i][j].second != 0)
        {
            ans.push_back(tracking[i][j].second);
            cnt += 1; // 문자 하나 찾음
        }

        int t1 = tracking[i][j].first.first, t2 = tracking[i][j].first.second;
        i = t1, j = t2;
    }

    for (auto i = ans.rbegin(); i != ans.rend(); i++)
        cout << *i;
    cout << '\n';

    return 0;
}