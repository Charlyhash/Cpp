#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
void printElem (const T& coll)
{
    for (const auto& elem : coll) 
    {
        cout << elem << endl;
    }
}

int main()
{
    vector<string> coll{"aa", "bb", "cc"};

    printElem(coll);

    system("pause");
    return 0;
}