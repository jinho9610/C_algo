#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

bool checked[200000001];

void getPrime()
{
    checked[0] = checked[1] = true;
    for (int i = 2; i <= sqrt(200000001); i++)
        if (!checked[i])
            for (int j = i + i; j <= 200000001; j += i)
                checked[j] = true;
}

string trans(int n, int k)
{
    char intToChar[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                          '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string str;
    while (n / k > 0)
    {
        str = intToChar[n % k] + str;
        n /= k;
    }
    str = intToChar[n % k] + str;
    return str;
}

int solution(int n, int k)
{
    int answer = 0;

    string result = trans(n, k);
    //cout << result << endl;

    //getPrime(); // 소수 미리 구해놓고

    stringstream ss(result);
    string token;
    vector<string> tokens;
    while (getline(ss, token, '0'))
    {
        if (token.length() != 0)
        {
            //cout << "?" << token <<' ' << token.size() << endl;
            tokens.push_back(token);
        }
    }

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].length() == 0)
            continue;
        if (!checked[stoi(tokens[i])])
        {
            //cout << stoi(tokens[i]) << "는 소수이다." << endl;
            answer++;
        }
    }

    return answer;
}

int main()
{
    getPrime(); // 소수 미리 구해놓고
    string str = "111111111";
    cout << stoi(str) << endl;
    cout << checked[111111111] << endl;
    while (true)
    {
        for (int n = 9800; n <= 1000000; n++)
            for (int k = 3; k <= 10; k++)
                cout << n << ' ' << k << ' ' << solution(n, k) << endl;
    }
    return 0;
}