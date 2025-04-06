#include <iostream>

using namespace std;

void f(int)
{
    cout << "f(int)" << endl;
}

void f(bool)
{
    cout << "f(bool)" << endl;
}

void f(void*)
{
    cout << "f(void*)" << endl;
}

int main(int argc, char *argv[])
{
    cout << "call f(0)" << endl;
    f(0);
    // cout << "call f(NULL)" << endl;
    // f(NULL); // not compile
    cout << "call f(nullptr)" << endl;
    f(nullptr);
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
