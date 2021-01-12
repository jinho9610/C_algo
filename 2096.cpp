#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <string.h>

using namespace std;

typedef long long ll;

int n;

int maxDp[3];
int minDp[3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 일반적인 dynamic programming 방식 이용하면 메모리 초과 발생. 입력받으면서 dp 배열 갱신하는 방식 이용
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    maxDp[0] = a, maxDp[1] = b, maxDp[2] = c;
    minDp[0] = a, minDp[1] = b, minDp[2] = c;

    int tmp_max_0, tmp_max_1, tmp_max_2;
    int tmp_min_0, tmp_min_1, tmp_min_2;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;

        tmp_max_0 = max(maxDp[0], maxDp[1]) + a;
        tmp_min_0 = min(minDp[0], minDp[1]) + a;
        tmp_max_1 = max(maxDp[0], max(maxDp[1], maxDp[2])) + b;
        tmp_min_1 = min(minDp[0], min(minDp[1], minDp[2])) + b;
        tmp_max_2 = max(maxDp[1], maxDp[2]) + c;
        tmp_min_2 = min(minDp[1], minDp[2]) + c;

        maxDp[0] = tmp_max_0, maxDp[1] = tmp_max_1, maxDp[2] = tmp_max_2;
        minDp[0] = tmp_min_0, minDp[1] = tmp_min_1, minDp[2] = tmp_min_2;
    }

    cout << max(maxDp[0], max(maxDp[1], maxDp[2])) << endl;
    cout << min(minDp[0], min(minDp[1], minDp[2])) << endl;

    return 0;
}