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

// ax+by-c => as+bt =r을 만족하는 s,t,r조합 찾기(r이 gcd(a, b)일 때)
int *eGcd(int a, int b)
{
    int s0 = 1, t0 = 0, r0 = a;
    int s1 = 0, t1 = 1, r1 = b;

    int temp;
    while (r1 != 0)
    {
        int q = r0 / r1;

        temp = r0 - q * r1; // 새로운 값
        r0 = r1;
        r1 = temp;

        temp = s0 - q * s1;
        s0 = s1;
        s1 = temp;

        temp = t0 - q * t1;
        t0 = t1;
        t1 = temp;
    }

    static int arr[3] = {s0, t0, r0};

    return arr;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << INFINITY << endl;

    // x: 인당 나눠줄 사탕의 수
    // y: 사탕 봉지의 수
    // a * x + 1 = b * y 를 만족하는 x, y를 찾아야함
    // a(-x) + by = 1

    // a, b 입력

    // d = gcd(a, b)
    // c%d == 0 이어야지 해를 가질 수 있음 : 베주 항등식

    // 확장 유클리드 호제법을 이용하여 s, t, r = d를 찾아냄

    // x0 = s * c / d
    // y0 = t * c / d

    // 일반해 공식 : x = x0 + b / d * k
    // y= y0 - a / d * k

    return 0;
}