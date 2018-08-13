#include <iostream>
#include <string>
using namespace std;

int main()
{
    string normal_str = "First line.\nSecond line.\nEnd of message.\n";
    string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";
    cout << normal_str << endl;
    cout << raw_str << endl;

    std::cout << R"(
        Hello,
        world!
    )" << endl;

    string raw_str1 = R"foo()")foo";
    // string raw_str2 = R"()")"; //error
    cout << raw_str1 << endl;

    system("pause");
    return 0;
}