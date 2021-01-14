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

struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;
    bool isHit;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    TrieNode *getChild(char c) // 자식 노드 정보 가져오기
    {
        return children[c - 'A'];
    }

    void clearHit()
    {
        isHit = false;
        for (int i = 0; i < 26; i++)
        {
            if (children[i] != NULL)
                children[i]->clearHit();
        }
    }
    bool hasChild(char c) // 자식있는 지 즉, 해당 문자가 이어지는지
    {
        return children[c - 'A'] != NULL;
    }
};

struct Trie
{
    TrieNode *root = new TrieNode();

    void insert(string word)
    {
        TrieNode *current = root;
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            int index = c - 'A';
            if (current->hasChild(c) == false) // 다음 문자를 갖는 노드가 없으면
            {
                current->children[c - 'A'] = new TrieNode(); // 생성
            }
            current = current->getChild(c); // current 포인터 옮기기
        }
        current->isEnd = true;
    }

    bool checkWord(string word)
    {
        TrieNode *current = root;
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if (current->hasChild(c)) // 알파벳 하나씩 따라간다
            {
                current = current->getChild(c); // 포인터 한칸씩 아래로 이동
            }
            else
                return false; // 문자열이 중간에 끊기면 false 반환
        }
        return current->isEnd; // 최종적으로 도착한 노드의 isEnd를 반환, 찾고자하는 문자열이 저장된 적이 있으면 true를 반환하게 됨
    }
};

int m, w;
char arr[4][4];
bool visited[4][4];
int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, 1, 0, -1};
int cnt = 0, sum = 0;
vector<char> sol;
string tmp, answer;

string stringCmp(string s1, string s2)
{
    if (s1.size() == s2.size())
    {
        if (s1.compare(s2) == -1)
            return s1;
        else
            return s2;
    }
    else
    {
        if (s1.size() < s2.size())
            return s2;
        else
            return s1;
    }
}

bool isInside(int x, int y)
{
    return (-1 < x && x < 4 && -1 < y && y < 4);
}

void dfs(int x, int y, int length, TrieNode *node)
{
    // 1. 체크인
    visited[x][y] = true;
    sol.push_back(arr[x][y]);

    // 2. 목적지인가
    if (node->isEnd == true && node->isHit == false)
    {
        node->isHit = true;   // 찾은 적이 있다고 적어두고
        sum += score[length]; // 점수 합산
        cnt++;                // 찾은 단어 수 하나 증가
        string f = "";        // 빈 문자열
        for (int i = 0; i < sol.size(); i++)
            f += sol[i];
        answer = stringCmp(answer, f);
    }

    // 3. 갈 수 있는 곳 순회
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isInside(nx, ny) && !visited[nx][ny] && node->hasChild(arr[nx][ny])) // 4. 갈 수 있는가?
            dfs(nx, ny, length + 1, node->getChild(arr[nx][ny]));                // 5. 간다.
    }

    // 6. 체크아웃
    visited[x][y] = false;
    sol.erase(sol.begin() + length - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Trie tr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        tr.insert(s);
    }

    cin >> w;
    tr.root->clearHit(); // 초기화

    for (int k = 0; k < w; k++)
    {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));

        answer = "";
        sum = 0, cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                char a;
                cin >> a;
                arr[i][j] = a;
            }
        }

        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                if (tr.root->hasChild(arr[x][y]))
                    dfs(x, y, 1, tr.root->getChild(arr[x][y]));
            }
        }
        tr.root->clearHit(); // 초기화
        cout << sum << " " << answer << " " << cnt << '\n';
    }

    return 0;
}