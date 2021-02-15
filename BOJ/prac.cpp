#include <set>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    set<vector<int>> s;
    s.insert({1, 2, 3});

    for (auto i : s)
    {
        for (auto a : i)
            cout << a << ' ';
        cout << '\n';
    }

    return 0;
}