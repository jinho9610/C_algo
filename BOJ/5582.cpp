// 풀이에 사용된 알고리즘: dp

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

string str1, str2;
int len1, len2, dp[4001][4001];

// p1, p2로 끝나는 문자열의 lcs
int calc(int p1, int p2)
{
    if (p1 < 0 || p2 < 0)
        return 0;

    if (dp[p1][p2])
        return dp[p1][p2];

    if (str1[p1] == str2[p2])
    {
        return dp[p1][p2] = calc(p1 - 1, p2 - 1) + 1;
    }
    else
        return dp[p1][p2] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str1 >> str2;
    len1 = str1.size();
    len2 = str2.size();

    int result = 0;
    for (int i = 0; i <= len1 - 1; i++)
        for (int j = 0; j <= len2 - 1; j++)
            result = max(result, calc(i, j));

    cout << result << endl;

    return 0;
}