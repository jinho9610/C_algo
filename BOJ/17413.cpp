/* BOJ 17413 단어뒤집기*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>

#define endl '\n'

using namespace std;

typedef long long ll;

string str;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	
	getline(cin, str);

	bool is_tag_open = false; // 태그가 열린적이 있는지
	
	string ans_str = ""; // 정답이 될 빈 문자열
	stack<char> stk; // 철자들을 뒤집기 위한 스택

	for (char ch : str) 
	{
		if (ch == '<') // 태그 열리면
		{
			is_tag_open = true; // 열렸다고 플래그 변경하고
			while (!stk.empty()) // 스택에 있는 모든 문자들을
			{
				ans_str += stk.top(); // 정답이 되는 문자열에 이어줌(뒤집힌형태로 이어붙혀짐)
				stk.pop();
			}
		}
		if (is_tag_open) // 태그가 열린 상태에서는
		{
			ans_str += ch; // 철자를 추가하되
			if (ch == '>') // 태그 닫힘 기호가 나오면
				is_tag_open = false; // 닫아줌
		}
		else // 태그가 닫힌 상태에서는
		{
			if (ch == ' ') // 공백을 만나면
			{
				while (!stk.empty()) // 뒤집기
				{
					ans_str += stk.top();
					stk.pop();
				}
				ans_str += ' ';
			}
			else stk.push(ch); // 공백전까지는 스택에 저장
		}
	}
	while (!stk.empty()) // 마지막에 스택에 남아있는 모든 문자들도 
	{
		ans_str += stk.top(); // 정답 문자열에 이어 붙힘
		stk.pop();
	}
	cout << ans_str << endl;

	return 0;
}
