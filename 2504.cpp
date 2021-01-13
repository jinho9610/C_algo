#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

class Element
{
public:
    bool type;
    int value;
    char command;

    Element(int value)
    {
        this->type = true;
        this->value = value;
    }
    Element(char command)
    {
        this->type = false;
        this->command = command;
    }
};

string str;
stack<Element> s;
ll result;

int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        char command = str[i];
        if (command == '(' || command == '[')
        {
            s.push(Element(command));
        }
        else if (command == ')')
        {
            int sum = 0;
            bool isInvalid = true;
            while (!s.empty())
            {
                Element element = s.top();
                s.pop();
                if (element.type) // 들어있던게 숫자라면
                {
                    sum += element.value;
                }
                else if (element.command == '(')
                {
                    if (sum == 0) // 숫자가 스택에 존재하지 않는 경우
                    {
                        s.push(Element(2));
                    }
                    else
                    {
                        s.push(Element(2 * sum));
                    }
                    isInvalid = false;
                    break;
                }
                else
                {
                    isInvalid = true;
                    break;
                }
            }
            if (isInvalid)
            {
                cout << 0 << endl;
                return 0;
            }
        }
        // [ ] 구현
        else if (command == ']')
        {
            int sum = 0;
            bool isInvalid = true;
            while (!s.empty())
            {
                Element element = s.top();
                s.pop();
                if (element.type) // 들어있던게 숫자라면
                {
                    sum += element.value;
                }
                else if (element.command == '[')
                {
                    if (sum == 0) // 숫자가 스택에 존재하지 않는 경우
                    {
                        s.push(Element(3));
                    }
                    else
                    {
                        s.push(Element(3 * sum));
                    }
                    isInvalid = false;
                    break;
                }
                else
                {
                    isInvalid = true;
                    break;
                }
            }
            if (isInvalid)
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    int result = 0;

    while (!s.empty())
    {
        if (s.top().type)
        {
            result += s.top().value;
            s.pop();
        }
    }

    if (!s.empty())
        cout << 0 << endl;

    else
        cout << result << endl;

    return 0;
}