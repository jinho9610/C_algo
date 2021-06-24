/* BOJ 1316 �׷� �ܾ� üĿ */
/* �ܼ� ����.. */
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
	char prev_char = 'a', cur_char = 'a'; // �ܼ� �ʱ�ȭ dummy �� 'a'
	for (int i = 0; i < word.length(); i++)
	{
		cur_char = word[i];

		// �̹� �� �� �����ߴ� ö�ڰ� �ٽ� �����ϰ�, ���� ö�ڿ��� ���Ӽ��� ���ٸ�
		if (visited[cur_char - 'a'] && prev_char != cur_char)
			return false; // �׷� �ܾ �ƴϴ�
		
		if (!visited[cur_char - 'a']) // ���ο� ö�ڰ� �����ϸ�
			visited[cur_char - 'a'] = true; // �����ߴٰ� ǥ��

		// ���� for�� ����� ���� ö�ڴ� �� ���� for�� step������ ö��
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
