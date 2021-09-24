#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    string S = "JINHO";
    for (int pos = 0; S[pos];)
    {
        n++;
        pos += n;
        cout << pos << endl;
    }

    return 0;
}