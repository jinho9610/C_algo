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
#include <unordered_map>

using namespace std;

typedef long long ll;

int w, h, g, e; // 가로, 세로, 묘비, 구멍
int arr[31][31];

unordered_map<pair<int, int>, pair<int, int>> um;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 인덱스 0부터 시작
    cin >> w >> h >> g;
    for (int i = 0; i < g; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = -1; // 묘비는 -1로 표시
    }

    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int x1, y1, x2, y2, t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;
    }

    return 0;
}