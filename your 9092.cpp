#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dic;

char board[5][5];
int visited[5][5];

int dx[8] = {1, 0, 0, -1, -1, 1, 1, -1};
int dy[8] = {0, 1, -1, 0, -1, 1, -1, 1};

int found[300005];
int max_score;
int max_len;
int max_idx;
int word_cnt;

void DFS(int word, int idx, int cur_x, int cur_y)
{
    if (dic[word].length() == idx && found[word] == 0)
    {
        found[word] = 1;
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
        if (idx > max_len)
        {
            max_len = idx;
            max_idx = word;
        }
        word_cnt++;
    }
    else
    {
        for (int k = 0; k < 8; k++)
        {
            int next_x = cur_x + dx[k];
            int next_y = cur_y + dy[k];

            if (next_x >= 0 && next_x < 4 && next_y >= 0 && next_y < 4 && !visited[next_x][next_y] && board[next_x][next_y] == dic[word][idx])
            {
                visited[next_x][next_y] = 1;
                DFS(word, idx + 1, next_x, next_y);
                visited[next_x][next_y] = 0;
            }
        }
    }
    visited[cur_x][cur_y] = 0;
}

int main()
{
    int w;
    scanf("%d", &w);

    string tmp = "";
    getline(cin, tmp);
    for (int i = 0; i < w; i++)
    {
        getline(cin, tmp);
        dic.push_back(tmp);
    }

    sort(dic.begin(), dic.end());
    getline(cin, tmp);

    int b;
    scanf("%d", &b);

    while (b--)
    {
        getline(cin, tmp);
        for (int i = 0; i < 4; i++)
        {
            getline(cin, tmp);
            for (int j = 0; j < 4; j++)
                board[i][j] = tmp[j];
        } // make board

        cout<<"board출력\n";
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
                cout<<board[i][j]<<' ';
            cout<<endl;
        }

        // initialize
        for (int i = 0; i < w; i++)
            found[i] = 0;
        max_score = 0;
        max_len = -1;
        max_idx = 0;
        word_cnt = 0;

        // find word
        for (int t = 0; t < w; t++)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (board[i][j] == dic[t][0] && found[t] == 0)
                    {
                        visited[i][j] = 1;
                        DFS(t, 1, i, j);
                    }
                }
            }
        }

        // output
        cout << max_score << " " << dic[max_idx] << " " << word_cnt << "\n";
    }
}