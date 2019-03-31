#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    string name;
    virtual void display(const string& val) {
        name = val;
        cout << "Base::display " << name << endl;
    }
};

class Derived: public Base
{
public:
    string dname;
    virtual void display(const std::string& val) {
        dname = val;
        static_cast<Base>(*this).display("hello");
        cout << "Derived::display name=" << name << " dname=" << dname << endl;
    }
};

int main(int, char*[])
{
    // 见 Effective C++ 条款 27
    Derived d;
    d.display("test");
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
