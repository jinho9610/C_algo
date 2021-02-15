#include <iostream>
#include <vector>

using namespace std;

int arr[5], selected[5];
vector<int> ans;
int result;

void dfs(int idx, int cnt)
{
    if (cnt == 3)
    {
        for (auto a : ans)
            cout << a << ' ';
        cout << endl;
        result++;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;
            ans.push_back(arr[i]);
            dfs(i, cnt + 1);
            ans.pop_back();
            selected[i] = false;
        }
    }
}

int main()
{

    arr[0] = 1, arr[1] = 2, arr[2] = 3, arr[3] = 4, arr[4] = 5;

    dfs(0, 0);
    cout << result << endl;

    return 0;
}