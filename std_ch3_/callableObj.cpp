#include <iostream>
#include <functional>
#include <memory>
#include <future>
using namespace std;

//function
int func(int x, int y)
{
    return x+y;
}
//lambda
auto l = [](int x, int y) {
    return x+y;
};

class C 
{
public:
    //function object
    int operator() (int x, int y) const 
    {
        return x + y;
    }
    //pointer to a member function
    int memfunc(int x, int y) const 
    {
        return x + y;
    }
};

int main()
{
    C c;
    shared_ptr<C> sp(new C);
    cout << std::bind(func, 1, 3)() << endl; //calls:func(1,3)
    cout << std::bind(l, 1, 3)() << endl; //calls:l(1,3)
    cout << std::bind(C(), 1, 3)() << endl; //calls:C::operator()(1,3)
    cout << std::bind(&C::memfunc, c, 1, 3)() << endl;//calls:c.memfunc(1,3)
    cout << std::bind(&C::memfunc, sp, 1, 3)() << endl;//calls:sp->memfunc(1,3)

    //异步调用
    std::future<int> fut = std::async(func, 1, 3); //calls:func(1,3)
    //wait for result
    cout << fut.get() << endl;
    std::async(l, 1, 3); //calls:l(1,3)
    std::async(c, 1, 3);  //calls:C::operator()(1,3)
    std::async(&C::memfunc, &c, 1, 4);//calls:c.memfunc(1,3)
    std::async(&C::memfunc, sp, 1, 3);//calls:sp->memfunc(1,3)

    system("pause");
    return 0;
}
