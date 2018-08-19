#include <iostream>
#include <functional>
using namespace std;

void demo1()
{
    int id = 5;
    auto f = [id] () mutable {
        cout << "id: " << id << endl;
        ++id;
    };
    id = 42;
    f();
    f();
    f();
    cout << "finally id:" << id << endl;
}

//返回一个函数，参数为int, int；返回值为int
std::function<int(int,int)> returnLambda()
{
    return [](int x, int y){
        return x*y;
    };
}

void demo2()
{
    auto lf = returnLambda();
    cout << lf(6,7) << endl;
}

int main()
{
    //demo1();
    demo2();


    system("pause");
    return 0;
}