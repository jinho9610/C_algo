/* BOJ 21921 블로그 */
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

#define endl '\n'

typedef long long ll;

int n, x, arr[250001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int ans = 0;
    int ans_cnt = 0;

    int sum = 0;
    for (int i = 1; i <= n - x + 1; i++)
    {
        if (i == 1) // 가장 처음에는 o(n)으로 구간합 계산하기
        {
            for (int idx = i; idx <= i + x - 1; idx++)
                sum += arr[idx];
            ans = sum;
            ans_cnt = 1;
        }
        else
        {
            // 새로운 구간 합이 현재까지 등장한 maximum 구간합 보다 큰 경우
            if (ans < sum - arr[i - 1] + arr[i + x - 1])
            {
                ans_cnt = 1;                             // 해당 합의 등장 횟수를 1로 초기화
                ans = sum - arr[i - 1] + arr[i + x - 1]; // maximum 구간합 갱신
            }
            // 새로운 구간 합이 현재까지 등장한 maximum 구간합과 동일한 경우
            else if (ans == sum - arr[i - 1] + arr[i + x - 1])
                ans_cnt++; // maximum 구간합 등장 횟수 1회 증가

            sum = sum - arr[i - 1] + arr[i + x - 1]; // 변경된 구간합으로 sum 갱신
        }
    }

    if (ans == 0)
        cout << "SAD" << endl;
    else
    {
        cout << ans << endl;
        cout << ans_cnt << endl;
    }

    return 0;
}