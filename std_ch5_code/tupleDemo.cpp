#include <iostream>
#include <tuple>
#include <complex>
#include <string>
using namespace std;

void test1()
{
    tuple<string, int ,int , complex<double>> t;
    tuple<int, float, string> t1(42, 6.3, "hello");

    cout << get<0>(t1) << endl;
    cout << get<1>(t1) << endl;
    cout << get<2>(t1) << endl;

    auto t2 = make_tuple(22, 44, "world");
    get<1>(t1) = get<1>(t2);
    cout << get<1>(t1) << endl;
    if (t1 < t2)
    {
        t1 = t2;
    }
}

void test2()
{
    tuple<int, float, string> t(42, 3.14, "hello");
    int i; 
    float f;
    string s;
    tie(i, f, s) =  t;
    cout << "i=" << i << ",f=" << f << ",s=" << s << endl;
}


int main()
{
    //test1();

    test2();


    system("pause");
    return 0;
}