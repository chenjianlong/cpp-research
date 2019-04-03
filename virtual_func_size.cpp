#include <iostream>

using namespace std;

class A
{
public:
    int a;
};

class B
{
public:
    virtual ~B() {
    }

    int b;
};

class C
{
public:
    virtual void f1() {
    }

    virtual ~C() {
    }

    int c;
};

int main(int, char *[])
{
    // gcc 下，输出为：
    // sizeof(A)=4
    // sizeof(B)=16
    // sizeof(C)=16
    // 结论：当类中含有虚函数时，其类的会大 8，（一个指针的大小）
    // 用于存放 vtbls 的地址。
    cout << "sizeof(A)=" << sizeof(A) << endl;
    cout << "sizeof(B)=" << sizeof(B) << endl;
    cout << "sizeof(C)=" << sizeof(C) << endl;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
