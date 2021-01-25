#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int n;
queue<int> q;

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
            q.push(t);
        }
        else if (command == "pop")
        {
            if (q.empty())
                cout << -1 << endl;
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (command == "size")
        {
            cout << q.size() << endl;
        }
        else if (command == "empty")
        {
            cout << q.empty() << endl;
        }
        else if (command == "front")
        {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.front() << endl;
        }
        else if (command == "back")
        {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.back() << endl;
        }
    }

    return 0;
}