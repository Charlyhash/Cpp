#include <string>

using namespace std;

class Name {
    private:
     std::string name;
     
    public:
    Name() {
    }

    Name(string n) : name(n) {}

    string getName() {
        return name;
    }
};