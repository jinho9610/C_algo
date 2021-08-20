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
vector<pair<int, int>> beers;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int v, c;
        cin >> v >> c;
        beers.push_back({v, c}); // 선호도, 도수 레벨
    }

    sort(beers.begin(), beers.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool
         { return p1.second < p2.second; }); // 술 도수 레벨 기준 오름차순 정렬

    priority_queue<int, vector<int>, cmp> pq; // 맥주 담을 주머니

    ll total = 0;
    for (auto beer : beers)
    {
        pq.push(beer.first); // 현재 맥주를 주머니에 담기 (맥주의 선호도로 해당 맥주 표현)
        total += beer.first; // 현재 주머니에 담긴 맥주들의 선호도 총 합

        if (pq.size() > n) // 이미 술이 n개 선택된 상황이었다면
        {
            // (직전의 삽입으로 주머니에 n + 1개의 맥주가 담겨있다면)
            total -= pq.top(); // 가장 작은 선호도의 술을 뺀다
            pq.pop();
        }

        // 주머니에 술이 n개 담겨있고, 담긴 술들의 선호도 총 합이 m 이상이라면
        if (pq.size() == n && total >= m)
        {
            cout << beer.second << endl; // 방금 넣은 맥주의 도수 레벨이 정답이므로 출력
            return 0;
        }
    }
    cout << -1 << endl; // 정답을 찾지 못한 경우 -1 출력

    return 0;
}