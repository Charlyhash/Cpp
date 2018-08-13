/*
列表初始化
*/
#include <iostream>

using namespace std;

int listSum(initializer_list<int> vals) 
{
    int ret{0};
    for (auto p : vals)
    {
        ret += p;
    }

    return ret;
}

int main() 
{
    cout << listSum({1,2,3,4,5}) << endl;;

    system("pause");
    return 0;
}