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
vector<int> nums;
vector<int> LtoR;
vector<int> RtoL;

// gcd(a, b) = gcd(b, a%b), a%b가 0이면 a가 gcd
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

bool check(int k, int gcd_val) // 뺀 수가 k일 때 나머지 수의 최대 공약수가 k의 약수이면 안된다
{
    return !(k % gcd_val == 0); // 이게 true면 정답이다.
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    nums.resize(n);
    LtoR.resize(n);
    RtoL.resize(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            LtoR[i] = nums[i];
        else
            LtoR[i] = gcd(nums[i], LtoR[i - 1]);
    }

    for (int i = n - 1; i > -1; i--)
    {
        if (i == n - 1)
            RtoL[i] = nums[i];
        else
            RtoL[i] = gcd(nums[i], RtoL[i + 1]);
    }

    int Max = -1, k = 0;
    for (int i = 0; i < n; i++)
    {
        int gcd_val = 0;

        if (i == 0)
        {
            gcd_val = RtoL[1];
        }
        else if (i == n - 1)
        {
            gcd_val = LtoR[i - 1];
        }
        else
        {
            gcd_val = gcd(LtoR[i - 1], RtoL[i + 1]);
        }

        if (check(nums[i], gcd_val))
        {
            int cur_max = max(Max, gcd_val);
            if (Max != cur_max)
            {
                k = nums[i];
                Max = cur_max;
            }
        }
    }

    cout << Max << ' ' << k << '\n';

    return 0;
}