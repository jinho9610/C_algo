#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> operation;
    priority_queue<int, vector<int>, less<int>> q;

    for (int i = 0; i < n; i++)
    {
        int op;
        cin >> op;
        operation.push_back(op);
    }

    for (int i = 0; i < n; i++)
    {
        if (operation[i] == 0)
        {
            if (q.empty())
                cout << 0 << "\n";
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
        {
            q.push(operation[i]);
        }
    }
    return 0;
}