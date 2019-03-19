#include <iostream>

using namespace std;

class Base {
public:
    Base() {
        cout << "call Base constructor" << endl;
        log();
    }

    virtual void log() {
        cout << "call log in Base" << endl;
    }
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

class Derived2: public Derived
{
public:
    Derived2() {
        cout << "call Derived2 constructor" << endl;
        log();
    }

    virtual void log() {
        cout << "call log in Derived2" << endl;
    }
};

int main(int, char *[])
{
    cout << "----------------Base------------------" << endl;
    Base b;
    cout << "----------------Derived------------------" << endl;
    Derived d;
    cout << "----------------Derived2------------------" << endl;
    Derived2 d2;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
