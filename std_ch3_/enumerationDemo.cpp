#include <iostream>
using namespace std;

enum class Salution : char {mr, ms, co, none};

int main()
{
    Salution s = Salution::co;
    switch(s)
    {
        case Salution::mr:
            cout << "mr" << endl;
            break;   
        case Salution::ms:
            cout << "mr" << endl;
            break;        
        case Salution::co:
            cout << "mr" << endl;
            break;
        default:
            cout << "none" << endl;
    }
    //int n = r; //error
    int n = static_cast<int>(s); //ok
    cout << n << endl;
    system("pause");
    return 0;
}