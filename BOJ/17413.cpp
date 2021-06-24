/* BOJ 17413 �ܾ������*/
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

	bool is_tag_open = false; // �±װ� �������� �ִ���
	
	string ans_str = ""; // ������ �� �� ���ڿ�
	stack<char> stk; // ö�ڵ��� ������ ���� ����

	for (char ch : str) 
	{
		if (ch == '<') // �±� ������
		{
			is_tag_open = true; // ���ȴٰ� �÷��� �����ϰ�
			while (!stk.empty()) // ���ÿ� �ִ� ��� ���ڵ���
			{
				ans_str += stk.top(); // ������ �Ǵ� ���ڿ��� �̾���(���������·� �̾������)
				stk.pop();
			}
		}
		if (is_tag_open) // �±װ� ���� ���¿�����
		{
			ans_str += ch; // ö�ڸ� �߰��ϵ�
			if (ch == '>') // �±� ���� ��ȣ�� ������
				is_tag_open = false; // �ݾ���
		}
		else // �±װ� ���� ���¿�����
		{
			if (ch == ' ') // ������ ������
			{
				while (!stk.empty()) // ������
				{
					ans_str += stk.top();
					stk.pop();
				}
				ans_str += ' ';
			}
			else stk.push(ch); // ������������ ���ÿ� ����
		}
	}
	while (!stk.empty()) // �������� ���ÿ� �����ִ� ��� ���ڵ鵵 
	{
		ans_str += stk.top(); // ���� ���ڿ��� �̾� ����
		stk.pop();
	}
	cout << ans_str << endl;

	return 0;
}
