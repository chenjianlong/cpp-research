#include <iostream>

using namespace std;

class Base {
public:
    Base() {
        cout << "call Base constructor" << endl;
        init();
    }

    void init() {
        cout << "call Base init" << endl;
        log();
    }

    virtual void log() = 0;
};

class Derived: public Base
{
public:
    Derived() {
        cout << "call Derived constructor" << endl;
        log();
    }

    virtual void log() {
        cout << "call log in Derived" << endl;
    }
};

int main(int, char *[])
{
    cout << "----------------Derived------------------" << endl;
    // 程序会崩溃，报错如下：
    // pure virtual method called
    // terminate called without an active exception
    Derived d;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
