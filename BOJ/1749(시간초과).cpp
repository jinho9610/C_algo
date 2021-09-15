/* BOJ 1749 점수따먹기 */
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

int n, m, arr[201][201], answer;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) // (i, j)는 부분 행렬의 좌측 상단 좌표
            for (int h = 1; h <= n; h++)
                for (int w = 1; w <= m; w++) // h, w는 부분 행렬의 세로와 가로 길이
                {
                    int sum = 0; // 부분 행렬 내 원소 총합
                    for (int x = i; x < i + h; x++)
                        for (int y = j; y < j + w; y++) // (x, y)는 부분 행렬 내 원소
                            sum += arr[x][y];

                    answer = max(answer, sum); // 부분 행렬 내 원소의 총합 중 최대 값 찾기
                }

    cout << answer << endl;

    return 0;
}