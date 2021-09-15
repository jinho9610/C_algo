#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    stringstream ss("안녕 하 세 요");
    //stringstream ss("hey who am i");
    string token;
    // while (getline(ss, token, 't'))
    //     cout << token << endl;
    while (ss >> token)
        cout << token << endl;

    return 0;
}