#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Name.h"

using namespace std;

int main() {
    cout << "Hello VS Code" << endl;
    cout << "hello " << endl;
    Name name = Name("abc");
    cout << name.getName() << endl;
    
    system("pause");
    return 0;
}