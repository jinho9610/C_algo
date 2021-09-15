/* BOJ 1748 소수&팰린드롬 */
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
bool arr[2000001];

void find_prime_number()
{
    memset(arr, 0x01, sizeof(arr));
    arr[1] = false;

    for (int i = 1; i * i < 2000001; i++)
    {
        if (arr[i] == false)
            continue;

        for (int j = i + i; j < 2000001; j += i)
            arr[j] = false;
    }
}

bool is_palindrome(int num)
{
    string s_num = to_string(num);
    string reversed_s_num(s_num.rbegin(), s_num.rend());

    if (s_num == reversed_s_num)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n;

    find_prime_number();

    for (int i = n;; i++)
    {
        if (!arr[i])
            continue;

        if (is_palindrome(i))
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}