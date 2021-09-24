/* Programmers 43163 단어 변환 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
int word_len;
bool selected[100];

void dfs(int idx, int depth, string& target, vector<string>& words)
{
    cout <<idx<<' '<<depth <<endl;
    if(depth != 0)
    {
        if(words[idx] == target)
        {
            answer = min(answer, depth);
            return;
        }
    }
    cout << "ddd" << endl;
    
    for(int i = 0; i < words.size(); i++)
    {
        if(i == idx)
            continue;
        
        if(selected[i])
            continue;
        
        int cnt = 0;
        for(int k = 0; k < word_len; k++)
            if(words[idx][k] != words[i][k])
                cnt++;
        
        if(cnt == 1)
        {
            selected[i] = true;
            dfs(i, depth + 1, target, words);
            selected[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    word_len = words[0].length();
    dfs(-1, 0, target, words);
    
    cout << answer << endl;
    
    return answer;
}

int main()
{
    vector<string> words{"hot", "dot", "dog", "lot", "log", "cog"};
    solution("hit", "cog", words);
    return 0;
}