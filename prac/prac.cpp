#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int ul = 1; ul <= s.length(); ++ul) // 단위
    {
        if (s.length() % ul != 0)
            continue;

        string ans = "";
        for (int i = 0; i <= s.length(); i += ul)
        {
            int a = i, b = i + ul;
            string token;
            token = s.substr(a, b);
            cout << "i: " << a << "\ti + ul: " << b << "\tul: " << ul << "\ttoken: " << token << endl;

            int cnt = 1;

            for (int j = i + ul; j <= s.length(); j += ul)
            {
                if (token == s.substr(j, j + ul))
                {
                    i = j + ul;
                    cnt++;
                }

                else
                    break;
            }

            cout << "cnt: " << cnt << endl;

            if (cnt == 1)
                ans += token;
            else
                ans = ans + to_string(cnt) + token;
        }
        cout << "단위 길이: " << ul << " - 압축 결과: " << ans << endl;
    }

    return answer;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    string a;
    cin >> a;
    //cout << solution(a) << endl;
    cout << a.substr(1, 2) << endl;
    cout << a.substr(2, 3) << endl;
    cout << a.substr(3, 4) << endl;
}