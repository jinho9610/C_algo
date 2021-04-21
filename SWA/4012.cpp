#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;

int result = 1e9;
int n, s[17][17], selected[17];
vector<int> A, B;

int calc_fav_diff() // 맛 계산용 함수
{
    int a_fav = 0;
    for (int a1 : A)
        for (int a2 : A)
            if (a1 != a2)
                a_fav += s[a1][a2];

    int b_fav = 0;
    for (int b1 : B)
        for (int b2 : B)
            if (b1 != b2)
                b_fav += s[b1][b2];

    return abs(a_fav - b_fav);
}

void dfs(int idx, int cnt)
{
    if (cnt == n / 2)
    {
        B.clear();
        // B 벡터 채워야겠지
        for (int i = 1; i <= n; i++)
            if (!selected[i]) // A식재료로 선택되지 않았다면
                B.push_back(i);

        result = min(result, calc_fav_diff());
        return;
    }

    for (int i = idx + 1; i <= n; i++)
    {
        selected[i] = true;
        A.push_back(i);
        dfs(i, cnt + 1);
        A.pop_back();
        selected[i] = false;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int t_num;

    cin >> t_num;

    for (int t = 1; t <= t_num; t++)
    {
        result = 1e9;
        cin >> n;

        memset(s, 0x00, sizeof(s)); // 시너지 배열 초기화
        memset(selected, 0x00, sizeof(selected));

        for (int i = 1; i <= n; i++) // 시너지 배열 입력
            for (int j = 1; j <= n; j++)
                cin >> s[i][j];

        dfs(0, 0);

        cout << "#" << t << " " << result << '\n';
    }

    return 0;
}