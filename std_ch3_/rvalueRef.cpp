#include <iostream>
#include <utility>
using namespace std;

class X 
{
public:
    X (const X& lvalue); //copy ctor
    X (X&& rvalue); //move ctor

    X& operator= (const X& lvalue); //copy assignment operator
    X& operator= (X&& rvalue); //move assignment operator
};

int main()
{

}