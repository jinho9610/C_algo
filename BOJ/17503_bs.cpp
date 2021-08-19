/* BOJ 17503 맥주 축제 */
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

int n, m, k;
vector<pair<ll, ll>> beers;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;

    int c_max = 0; // 도수 레벨 중 최대 값
    for (int i = 0; i < k; i++)
    {
        int v, c;
        cin >> v >> c;
        beers.push_back({v, c}); // 선호도, 도수 레벨
        c_max = max(c_max, c);
    }

    sort(beers.begin(), beers.end(), [](pair<ll, ll> p1, pair<ll, ll> p2) -> bool
         { return p1.second < p2.second; });

    ll ans = 1e13;
    ll left_idx = 1, right_idx = c_max;
    while (left_idx <= right_idx)
    {
        ll mid = (left_idx + right_idx) / 2;

        ll total = 0;
        vector<ll> candis;
        for (auto beer : beers)
        {
            if (beer.second > mid)
                break;

            candis.push_back(beer.first);
        }

        if (candis.size() < n) // 마실 수 있는 맥주가 n개 조차 안되는 상황
        {
            left_idx = mid + 1;
            continue;
        }

        sort(candis.begin(), candis.end(), [](ll a, ll b) -> bool
             { return a > b; });

        for (int i = 0; i < n; i++)
            total += candis[i];

        if (total < m)
            left_idx = mid + 1;
        else
        {
            right_idx = mid - 1;
            ans = min(ans, mid);
        }
    }

    cout << (ans != 1e13 ? ans : -1) << endl;

    return 0;
}