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

int n;
int arr[1000001], dp[1000001], LIS[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        dp[i] = 1;

    LIS[0] = arr[0];
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (LIS[idx] < arr[i])
        {
            LIS[++idx] = arr[i];
            dp[i] = idx + 1; // 길이니까
        }
        else // 현재 LIS 중 가장 큰 수보다는 작다면 들어갈 위치 찾기
        {
            int idx2 = lower_bound(LIS, LIS + idx, arr[i]) - LIS;
            LIS[idx2] = arr[i];
            dp[i] = idx2 + 1;
        }
    }

    int result = idx + 1; // LIS의 마지막 인덱스 idx 이므로 길이는 + 1
    cout << result << '\n';

    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i] == result)
        {
            ans.push_back(arr[i]);
            result--;
            if (result == 0)
            
                break;
        }
    }

    for (auto iter = ans.rbegin(); iter != ans.rend(); iter++)
        cout << *iter << ' ';

    return 0;
}