#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int t, n, m;
int A[1001], B[1001];

int main()
{
    cin >> t >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> B[i];

    int a_start = 0, a_end = 0, b_start = 0, b_end = 0, sum = 0, cnt = 0;
    while (1)
    {
        for (int i = a_start; i <= a_end; i++)
        {
            sum += A[i];
        }
        for (int i = b_start; i <= b_end; i++)
        {
            sum += B[i];
        }
        if (sum < t)
            b_end++;

        else if (sum > t)
        {
            if (++b_start == m)
            {
                a_start++;
                b_start = 0, b_end = 0;
            }
        }
    }
    return 0;
}