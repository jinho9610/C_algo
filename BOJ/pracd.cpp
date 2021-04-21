#include <iostream>
#include <vector>

#define MAX 6
using namespace std;

int Arr[MAX];
bool Select[MAX];
vector<int> v;

void DFS(int Idx, int Cnt)
{
    if (Cnt == 3)
    {
        for (auto a : v)
            cout << a << ' ';
        cout << endl;
        return;
    }

    for (int i = Idx + 1; i < MAX; i++)
    {
        v.push_back(i);
        DFS(i, Cnt + 1);
        v.pop_back();
    }
}

int main(void)
{
    Arr[1] = 1;
    Arr[2] = 2;
    Arr[3] = 3;
    Arr[4] = 4;
    Arr[5] = 5;

    DFS(0, 0);
}
