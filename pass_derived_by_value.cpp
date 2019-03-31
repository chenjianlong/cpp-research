#include <iostream>

using namespace std;

class Base
{
public:
    virtual void display() {
        cout << "display on Base" << endl;
    }
};

class Derived: public Base
{
public:
    virtual void display() {
        cout << "display on Derived" << endl;
    }
};

void display(Base b)
{
    b.display();
}

int main(int, char *[])
{
    Base b;
    display(b);

    cout << endl;
    Derived d;
    display(d);
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
