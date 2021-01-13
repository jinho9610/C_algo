#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

int n;
stack<int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int t;
            cin >> t;
            s.push(t);
        }
        else if (command == "pop")
        {
            if (s.empty())
                cout << -1 << endl;
            else
            {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (command == "size")
        {
            cout << s.size() << endl;
        }
        else if (command == "empty")
        {
            cout << s.empty() << endl;
        }
        else if (command == "top")
        {
            if (s.empty())
                cout << -1 << endl;
            else
            {
                cout << s.top() << endl;
            }
        }
    }

    return 0;
}