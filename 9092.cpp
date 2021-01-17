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

int w, b;
vector<string> dict;
char board[5][5];
int visited[5][5];
int dx[8] = {1, 0, 0, -1, -1, 1, 1, -1};
int dy[8] = {0, 1, -1, 0, -1, 1, -1, 1};

int found[300005];
int max_score;
int max_len;
int max_idx;
int word_cnt;

void dfs(int word, int idx, int x, int y)
{
    visited[x][y] = 1;
    idx++;
    if (dict[word].length() == idx && found[word] == 0) // 목적 달성했는지
    {
        found[word] = -1; // 찾으면 -1로 표시

        if (idx == 3 || idx == 4)
            max_score += 1;
        else if (idx == 5)
            max_score += 2;
        else if (idx == 6)
            max_score += 3;
        else if (idx == 7)
            max_score += 5;
        else if (idx == 8)
            max_score += 11;

        if (idx > max_len) // 현재 찾은 단어의 길이가, 지금까지 찾은 단어의 길이보다 길다면 갱신
        {
            max_len = idx;
            max_idx = word; // 가장 긴 길이의 단어 위치(dict나 found 상에서의 위치) 표시
        }
        word_cnt++; // 찾은 단어 수 하나 증가
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > -1 && nx < 4 && ny > -1 && ny < 4 && !visited[nx][ny] && board[nx][ny] == dict[word][idx]) // 4. 갈수있다면
            {
                dfs(word, idx, nx, ny); // 5. 간다
            }
        }
    }
    visited[x][y] = 0;
    idx--;
}

int main()
{

    cin >> w;

    string tmp = "";
    for (int i = 0; i < w; i++)
    {
        cin >> tmp;
        dict.push_back(tmp);
    }

    sort(dict.begin(), dict.end()); // 게임 중 찾아야할 단어들 입력 및 정렬 종료

    cin >> b;
    for (int k = 0; k < b; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> tmp;
            for (int j = 0; j < 4; j++)
                board[i][j] = tmp[j];
        }

        for (int i = 0; i < w; i++)
            found[i] = 0;
        max_score = 0, max_len = -1, max_idx = 0, word_cnt = 0;

        for (int t = 0; t < w; t++)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (board[i][j] == dict[t][0] && found[t] == 0) // 해당 단어를 찾은적이 없다면, 첫 글자부터 찾고 dfs 돌리기 시작
                    {
                        dfs(t, 0, i, j);
                    }
                }
            }
        }

        cout << max_score << ' ' << dict[max_idx] << ' ' << word_cnt << '\n';
    }

    return 0;
}