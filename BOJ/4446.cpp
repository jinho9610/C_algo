/* BOJ 4446 ROT13 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>

#define endl '\n'

using namespace std;

typedef long long ll;

string str;
char vowel[12] = { 'a', 'i', 'y', 'e', 'o', 'u', 'a', 'i', 'y', 'e', 'o', 'u' };
char consonant[40] = { 'b','k','x','z','n','h','d','c','w','g','p','v','j','q','t','s','r','l','m','f'
					, 'b','k','x','z','n','h','d','c','w','g','p','v','j','q','t','s','r','l','m','f' };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	while (getline(cin, str))
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (isalpha(str[i]) == 0)
				continue;

			bool is_upper = false;
			// 대, 소문자 확인
			if (isupper(str[i]))
			{
				is_upper = true;
				str[i] = tolower(str[i]);
			}

			bool is_vowel = false;
			if (str[i] == 'a' || str[i] == 'i' || str[i] == 'y' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u')
				is_vowel = true;

			if (is_vowel) // str[i]가 모음인 경우
			{
				for (int j = 6; j < 12; j++)
				{
					if (str[i] == vowel[j])
					{
						str[i] = vowel[j - 3];
						break;
					}
				}
			}
			else // str[i]가 자음인 경우
			{
				for (int j = 20; j < 40; j++)
				{
					if (str[i] == consonant[j])
					{
						str[i] = consonant[j - 10];
						break;
					}
				}
			}

			if (is_upper) // 원래 대문자 였던 경우
				str[i] = toupper(str[i]);
		}

		cout << str << endl;
	}

	return 0;
}
