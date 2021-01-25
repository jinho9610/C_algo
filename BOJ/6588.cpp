#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;

const int Max = 1000000;
bool arr[Max + 1];
int minFactor[Max + 1];

vector<int> prime;
bool check[Max + 1];

void eratosthenes()
{
    for (int i = 2; i * i <= Max; i++)
    {
        if (!check[i])
        {
            for (int j = i * i; j <= Max; j += i)
                check[j] = true;
        }
    }
    for (int i = 3; i < Max + 1; i++)
    {
        if (!check[i])
            prime.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    eratosthenes();

    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;

        bool found = false;
        for (int i = 0; i < prime.size(); i++)
        {
            if (prime[i] <= n / 2 && !check[n - prime[i]])
            {
                cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Goldbach's conjecture is wrong." << '\n';
    }

    return 0;
}