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

int a, b, c, d;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> b >> a >> d >> c;

    int numerator = b * c + a * d;
    int denominator = a * c;

    int theirGcd = gcd(numerator, denominator);

    numerator /= theirGcd;
    denominator /= theirGcd;

    cout << numerator << ' ' << denominator << '\n';

    return 0;
}