## C++语言新特性

* Template表达式内的空格：在两个template表达式的闭符之间放一个空格已经过了
* nullptr 空指针
* auto类型自动推导
* 一致性初始化和初值列表：一致性初始化是说，面对任何初始化动作，都可以使用相同的语法，即大括号`{}`。需要注意的是，窄化——精度降低或者造成数值变动是不成立的。`class template std::initializer_list<>`支持一些列值得初始化。例子：
```
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
```

* Range-Base for循环：为了避免每个元素的copy ctor和dtor,需要将当前元素声明为一个const reference.
```
template <typename T>
void printElem (const T& coll)
{
    for (const auto& elem : coll) 
    {
        cout << elem << endl;
    }
}
```

* Move语义和Rvalue Reference: 凡是真正的存在内存当中，而不是寄存器当中的值就是左值，其余的都是右值。其实更通俗一点的说法就是：凡是取地址（&）操作可以成功的都是左值，其余都是右值。Rvalue表示右值，可以复制给一个变量。当类X包含move构造函数时，不会发生复制操作，而是直接赋予了新对象。对于复制构造函数也可以有move复制构造函数

```
class X 
{
public:
    X (const X& lvalue); //copy ctor
    X (X&& rvalue); //move ctor

    X& operator= (const X& lvalue); //copy assignment operator
    X& operator= (X&& rvalue); //move assignment operator
};
```

* Rvalue和Lvalue Reference的重载规则

如果你只实现void foo(X&);而没有实现void foo(X&&); 
行为如同c++98；foo()可因lvalue但不可因rvalue被调用。
实现：void foo(const X&); 
未实现：void foo(X&&); 
行为：如同c++98，foo()可因lvalue也可因rvalue被调用。
实现：void foo(X&); void foo(X&&); 或者 
void foo(const X&); void foo(X&&); 
行为：你可以区分“为rvalue服务”和“为lvalue服务”的版本被允许且应该提供move语义。也就是说，它可以“偷取”实参的内部状态和资源。
实现：void foo(X&&); 
未实现：void foo(X&&); void foo(const X&); 
行为：foo（）可因rvalue被调用，但是当你尝试以lvalue调用它，会触发编译错误。因此，这里只提供move（）语义。

*  Raw String Literal
C++11 提供了原生字符串的支持,同时也支持定义符`R"delim(...)delim"`
```
 string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";

string raw_str1 = R"foo()")foo"; //OK
string raw_str2 = R"()")";//error
```