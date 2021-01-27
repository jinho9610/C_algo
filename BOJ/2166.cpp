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
pair<double, double> vertex[10001];
double result = 0;

double calcTri(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    ll x1 = p1.first, y1 = p1.second;
    ll x2 = p2.first, y2 = p2.second;
    ll x3 = p3.first, y3 = p3.second;

    double area = 0.5 * ((x1 * y2 - x2 * y1) + (x2 * y3 - x3 * y2) + (x3 * y1 - x1 * y3));

    return area;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) // 다각형을 구성하는 점들
    {
        double a, b;
        cin >> a >> b;
        vertex[i] = {a, b};
    }

    for (int i = 3; i <= n; i++) // n-2개의 삼각형
    {
        // 1, i-1, i가 구성하는 삼각형의 넓이 구하기
        result += calcTri(vertex[1], vertex[i - 1], vertex[i]);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(result) << '\n';

    return 0;
}