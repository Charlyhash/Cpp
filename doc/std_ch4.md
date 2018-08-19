# 一般概念

## 命名空间

namepsaced指 标识符的某种隔间范围，可发生于任何源码文件。C++标准的namespace:
* std::rel_ops
* std::chrono
* std::placeholders
* std::regex_constants
* std::this_thread

## 头文件名称与格式

```
//头文件无后缀名
#include<string>
//前缀c,表示c标准头文件
#include<cstring>
```

## 差错和异常处理

* 标准库部分支持差错处理，检查所有可能的差错，并在差错发生时抛出异常
* 其他部分，效率重于安全，不检查逻辑查找，只在运行期发生差错才抛出异常

#### 标准的Exception Class

被语言本身或标准库抛出的异常都派生自基类`exception`(头文件为`<exception>`),由若干标准异常类的基类，共同构成一个类体系,如下图所示：
![std_exception](./img/std_exception.png)

#### 异常类的成员

`what()`:获取“类型意外的附加信息”
* 差错码：用于封装差错码值得对象。`std::error_code`
* 差错状态：差错描述之可移植抽象层的独享。`std::error_condition`


## 可被调用的对象

callable object:可被某种方式调用淇某些函数的对象，包括：
* 一个函数
* 一个指向成员函数的指针
* 一个函数对象
* 一个lambda

## 并发及多线程

* 内核语言层面：（1）定义了新的内存模型；（2）引入新关键字`thread_local`，线程特定变量和对象
* 标准库层面：（1）线程安全相关的保证；（2）支持类和函数的并发运算

## 分配器介绍

C++在许多地方采用特殊对象处理内存的分配和归还，称为allocator。一般采用默认allocator,定义如下：
```
namespace std 
{
    template<typename T>
    class allocator;
}
```