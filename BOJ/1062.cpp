/* BOJ 가르침 1062 */
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

int n, k, ans = 0;
bool learned[26];
char letters[26];
string words[55];

void dfs(char ch, int cnt)
{
    if (cnt >= k - 5)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            string &word = words[i];
            bool can_read = true;
            for (char c : word)
            {
                if (learned[c - 'a'] == false)
                {
                    can_read = false;
                    break;
                }
            }
            if (can_read)
                cnt++;
        }

        ans = max(ans, cnt);
        return;
    }

    for (char c = ch + 1; c <= 'z'; c++)
    {
        if (!learned[c - 'a'])
        {
            learned[c - 'a'] = true;
            dfs(c, cnt + 1);
            learned[c - 'a'] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> k;
    if (k < 5)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
        cin >> words[i];

    learned['a' - 'a'] = true;
    learned['n' - 'a'] = true;
    learned['t' - 'a'] = true;
    learned['c' - 'a'] = true;
    learned['i' - 'a'] = true;
    dfs((char)((int)'a' - 1), 0);

    cout << ans << endl;

    return 0;
}