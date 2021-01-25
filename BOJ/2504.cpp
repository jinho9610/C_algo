#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

string str;
stack<char> s;
ll result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tmp = 1;
    bool impossible = false;
    cin>>str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            tmp *= 2;
            s.push('(');
        }
        else if (str[i] == '[')
        {
            tmp *= 3;
            s.push('[');
        }

        else if (str[i] == ')' && (s.empty() || s.top() != '('))
        {
            impossible = true;
            break;
        }
        else if (str[i] == ']' && (s.empty() || s.top() != '['))
        {
            impossible = true;
            break;
        }
        else if (str[i] == ')')
        {
            if (str[i - 1] == '(')
                result += tmp;
            s.pop();
            tmp /= 2;
        }
        else if (str[i] == ']')
        {
            if (str[i - 1] == '[')
                result += tmp;
            s.pop();
            tmp /= 3;
        }
    }
    if (impossible || !s.empty())
        cout << 0 << '\n';
    else
    {
        cout << result << '\n';
    }

    return 0;
}