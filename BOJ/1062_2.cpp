#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int n, k;
bool visited[26];
string words[51];

int Max;
int selectedCount;

/*모범답안*/
void ansDfs(int idx)
{
    //1. 체크인
    //2. 목적지인가?
    if (selectedCount >= k) //배울 수 있는 만큼 배웠는가
    {                       //max 갱신
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            bool isPossible = true; // 처음에는 어떤 단어든 읽을 수 있다고 가정
            for (int j = 0; j < words[i].size(); j++)
            {
                if (!visited[words[i][j] - 'a'])
                {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible)
                count++;
        }
        Max = max(Max, count);
        return;
    }

    //3. 연결된 곳 순회 idx + 1 ~
    for (int i = idx + 1; i < 26; i++)
    {
        //4. 갈 수 있는가
        if (!visited[i])
        {
            visited[i] = true;
            selectedCount++;
            ansDfs(i);       // 5. 간다.
            selectedCount--; // 6. 체크 아웃
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n;
    cin >> k;

    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true;
    selectedCount = 5; // 이미 다섯개 선정

    for (int i = 0; i < n; i++)
        cin >> words[i];

    if (k < 5)
    {
        cout << 0 << endl;
        return 0;
    }

    //Max = countWords();

    // for (int i = 0; i < 26; i++)
    //     if (!visited[i])
    //         ansDfs(i);
    ansDfs(-1);

    cout << Max << endl;

    return 0;
}