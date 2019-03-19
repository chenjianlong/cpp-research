#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base() = 0;
};

// Effective C++ 条款 07，析构函数必须要有定义，即使是纯虚函数
Base::~Base()
{
    cout << "~Base" << endl;
}

class Derived: public Base
{
public:
    virtual ~Derived() {
        cout << "~Derived" << endl;
    }
};

int main(int, char *[])
{
    Derived d;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
