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
vector<int> coins;
bool isPossible[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        coins.push_back(c);
    }

    sort(coins.begin(), coins.end());

    int target = 1;
    // 만들 수 없는 양의 정수 금액 중 최소 값
    for (auto coin : coins)
    {
        if (target < coin)
        {
            cout << target << endl;
            return 0;
        }
        else
            target += coin;
    }

    return 0;
}