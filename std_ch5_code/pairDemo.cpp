#include <iostream>
#include <utility>
#include <functional>
using namespace std;

void test1()
{
    typedef pair<int, float> IntFloatPair;
    IntFloatPair p(42, 3.14);
    //可以使用如下两种方式获取p的元素的值
    cout << std::get<0>(p) << endl;
    cout << p.second << endl;

    //返回其元素个数
    cout << tuple_size<IntFloatPair>::value << endl;
    //返回IntFloatPair第一个元素的类型
    tuple_element<0, IntFloatPair>::type a = 5.5; //a为int类型
    cout << a << endl; //5,自动截断
}

class A 
{
private:
    int a;
public:
    A(int aa):a(aa) {}
    A(A& aa) { a = aa.a;} 
    int get() { return a;}
};

void test2()
{
    //pair<A, int> p; //error

    int i = 2;
    //使用ref()，表示为引用语义，指向i,因此对这个值得操作会影响i的值
    auto p = make_pair(ref(i), ref(i)); //pair<int&, int&>
    ++p.first;
    ++p.second;
    cout << "i = " << i << endl; //i=4
}

int main()
{
    //test1();
    test2();
    system("pause");
    return 0;
}