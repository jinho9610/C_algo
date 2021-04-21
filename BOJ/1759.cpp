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

int l, c, vowel_cnt, conso_cnt;
char letters[16];
bool isVowel[26];
vector<char> ans;

void dfs(int idx, int cnt)
{
    if (cnt == l)
    {
        if (vowel_cnt >= 1 && conso_cnt >= 2)
        {
            for (auto a : ans)
                cout << a;
            cout << '\n';
        }
        return;
    }

    for (int i = idx + 1; i <= c; i++)
    {
        if (isVowel[letters[i] - 'a'])
            vowel_cnt++;
        else
            conso_cnt++;
        ans.push_back(letters[i]);

        dfs(i, cnt + 1);

        if (isVowel[letters[i] - 'a'])
            vowel_cnt--;
        else
            conso_cnt--;
        ans.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> l >> c;

    for (int i = 1; i <= c; i++)
        cin >> letters[i];

    isVowel['a' - 'a'] = true;
    isVowel['e' - 'a'] = true;
    isVowel['i' - 'a'] = true;
    isVowel['o' - 'a'] = true;
    isVowel['u' - 'a'] = true;

    sort(letters + 1, letters + c + 1);

    dfs(0, 0);

    return 0;
}