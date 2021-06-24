/* BOJ 1316 그룹 단어 체커 */
/* 단순 구현.. */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>

#define endl '\n'

using namespace std;

typedef long long ll;

int n;
bool visited[26];
vector<string> words;

bool is_GroupWord(string word)
{
	char prev_char = 'a', cur_char = 'a'; // 단순 초기화 dummy 값 'a'
	for (int i = 0; i < word.length(); i++)
	{
		cur_char = word[i];

		// 이미 한 번 등장했던 철자가 다시 등장하고, 이전 철자와의 연속성이 없다면
		if (visited[cur_char - 'a'] && prev_char != cur_char)
			return false; // 그룹 단어가 아니다
		
		if (!visited[cur_char - 'a']) // 새로운 철자가 등장하면
			visited[cur_char - 'a'] = true; // 등장했다고 표시

		// 다음 for문 실행시 이전 철자는 곧 현재 for문 step에서의 철자
		prev_char = cur_char; 
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	int cnt = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		memset(visited, 0x00, sizeof(visited));
		string word;
		cin >> word;
		if (is_GroupWord(word))
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}
