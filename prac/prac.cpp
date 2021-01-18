#include <iostream>

using namespace std;

int pr[100];

int find_parent(int x)
{
    if (x == pr[x])
        return x;

    return pr[x] = find_parent(pr[x]);
}

int main()
{
    for (int i = 1; i <= 10; i++)
        pr[i] = i;

    for (int i = 1; i <= 10; i++)
    {
        find_parent(i);
    }
    return 0;
}