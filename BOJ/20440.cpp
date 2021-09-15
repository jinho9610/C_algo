/* BOJ 20440 니가 싫어 싫어 너무 싫어 싫어 오지 마 내게 찝쩍대지마~ */
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

int n;
vector<pair<int, int>> times;

struct cmp
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        times.push_back({s, e});
    }

    sort(times.begin(), times.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool
         {
             if (p1.first == p2.first)
                 return p1.second < p2.second;
             else
                 return p1.first < p2.first;
         });

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    int answer = 1;
    int s = times[0].first, e = times[0].second;
    pq.push(times[0]);

    for (int i = 1; i < n; i++)
    {
        pair<int, int> &time = times[i];

        while (!pq.empty() && pq.top().second < time.first) // 겹치지 않는 구간은 pq에서 삭제
            pq.pop();

        if (!pq.empty() && time.first == pq.top().second) // 직전에 삽입한 구간과 이어지는 구간인 경우
        {
            if (pq.top().second == e)
                e = time.second; // 구간 이어붙이기
            pq.pop();
        }

        pq.push(time);
        if (answer < pq.size())
        {
            answer = pq.size();
            s = time.first;
            e = pq.top().second;
        }
    }

    cout << answer << endl;
    cout << s << ' ' << e << endl;

    return 0;
}