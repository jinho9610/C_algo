/* BOJ 1622 공통 순열 */
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

string a, b;
int a_letters[26], b_letters[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    while (getline(cin, a) && getline(cin, b))
    {
        memset(a_letters, 0x00, sizeof(a_letters));
        memset(b_letters, 0x00, sizeof(b_letters));

        vector<char> v;

        for (char c : a)
            a_letters[c - 'a']++;
        for (char c : b)
            b_letters[c - 'a']++;

        for (int i = 0; i < 26; i++)
            for (int j = 0; j < min(a_letters[i], b_letters[i]); j++)
                v.push_back(i + 'a');

        sort(v.begin(), v.end());
        for (char c : v)
            cout << c;
        cout << endl;
    }

    return 0;
}