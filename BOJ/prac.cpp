#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 3, 5, 7, 9};

    auto it = upper_bound(v.begin(), v.end(), 2);

    //cout << distance(v.begin(), it) << endl;
    cout << *it << endl;

    return 0;
}
