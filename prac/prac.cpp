#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

int arr[5];
int select[5];
vector<int> v;

void combi(int idx, int cnt) // 조합
{
    cout << "idx: " << idx << "    cnt: " << cnt << endl;
    if (cnt == 3)
    {
        cout << "cnt == 3: ";
        for (int i = 0; i < 5; i++)
        {
            if (select[i])
                cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < 5; i++)
    {
        if (select[i])
            continue;
        select[i] = true;
        combi(i, cnt + 1); // 방문하지 않은 곳이면 dfs
        select[i] = false;
    }

    cout << "others completed:::   idx: " << idx << "     cnt: " << cnt << endl;
}

void repeat_combi(int idx, int cnt)
{
    if (cnt == 3)
    {
        for (int i = 0; i < 3; i++)
            cout << select[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i < 5; i++)
    {
        select[cnt] = arr[i];
        repeat_combi(i, cnt + 1);
    }
}

void permute(int cnt) // 순열
{
    if (cnt == 3)
    {
        for (auto n : v)
            cout << n << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (select[i])
            continue;

        select[i] = true;
        v.push_back(arr[i]);
        permute(cnt + 1);
        v.pop_back();
        select[i] = false;
    }
}

int main()
{
    // 어떤 배열을 가지고 순열을 만드는 법

    for (int i = 0; i < 5; i++)
        arr[i] = i + 1;

    // combi(0, 0);
    // permute(0);
    // repeat_combi(0, 0);

    string s = "jinho";

    int a;
    cin >> a;

    if (isdigit(a + '0'))
        cout << "number" << endl;

    return 0;
}