#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define endl '\n'

typedef long long ll;

int n, t_num, t;
int min_val = 1e9, max_val = -1e9, limits[4];
vector<int> nums;
vector<int> opers;
bool cannotCalc = false;

int calc()
{
    int val = nums[0];

    for (int i = 1; i < n; i++)
    {
        int oper = opers[i - 1];
        int num = nums[i];

        if (oper == 0)
        {
            val += num;
        }
        else if (oper == 1)
        {
            val -= num;
        }
        else if (oper == 2)
        {
            val *= num;
        }
        else if (oper == 3)
        {
            if (num == 0) // 0이면 못나눔
            {
                cannotCalc = true;
                break;
            }
            else
                val /= num;
        }
    }

    return val;
}

void dfs(int cnt)
{
    if (cnt == n - 1) // 연산자 개수 모두 모음
    {
        int val = calc();

        if (!cannotCalc)
        {
            min_val = min(min_val, val);
            max_val = max(max_val, val);
            cannotCalc = false;
        }

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (limits[i] > 0)
        {
            opers.push_back(i); // 0 더하기, 1 빼기, 2 곱하기, 3 나누기
            limits[i]--;

            dfs(cnt + 1);

            limits[i]++;
            opers.pop_back();
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> t_num;

    for (t = 1; t <= t_num; t++)
    {
        min_val = 1e9, max_val = -1e9;
        nums.clear();
        opers.clear();
        cannotCalc = false;
        memset(limits, 0xff, sizeof(limits));

        cin >> n;

        for (int i = 0; i < 4; i++)
        {
            int a;
            cin >> a;
            limits[i] = a;
        }

        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            nums.push_back(a);
        }

        dfs(0);

        cout << "#" << t << " " << abs(min_val - max_val) << endl;
    }
    return 0;
}