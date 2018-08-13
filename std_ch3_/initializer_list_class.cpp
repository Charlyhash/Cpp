#include <iostream>
using namespace std;

class P
{
public:
    P(int a, int b):x(a), y(b) {}
    P(initializer_list<int> vals)
    {
        x = *vals.begin();
        y = *(vals.begin()+1);
    }

    void print()
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
private:
    int x;
    int y;
};

int main() 
{
    P p(1,2);
    p.print();

    P q{3,4};
    q.print();

    system("pause");
    return 0;
}