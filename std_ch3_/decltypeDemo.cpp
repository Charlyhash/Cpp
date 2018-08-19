#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, float> coll;
    decltype(coll) elem;
    coll.insert(pair<string, float>("abc", 12.3));
    elem.insert(pair<string, float>("abc", 12.3));

    system("pause");
    return 0;
}