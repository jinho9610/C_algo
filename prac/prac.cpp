#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    string s1 = "BlockDMask";
    string s2 = "BlogBlogBlogBlog";

    cout << s1.substr(0, 3) << endl;
    cout << s2.substr(4, 6) << endl;
    cout << s1.compare(0, 3, s2, 4, 6) << endl;

    return 0;
}