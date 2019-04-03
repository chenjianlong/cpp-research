#include <iostream>

using namespace std;

class A
{
public:
    int a_;
};

//class B: public A
class B: public virtual A
{
public:
    int b_;
};

//class C: public A
class C: public virtual A
{
public:
    int c_;
};

class D: public B, C
{
public:
    int d_;
};

int main(int, char *[])
{
    // 菱形继承简析：
    // 非虚继承时输出：
    // sizeof(A)=4
    // sizeof(B)=8 addr=0x7ffd38f05600
    // sizeof(C)=8 addr=0x7ffd38f05608
    // sizeof(D)=20 addr=0x7ffd38f05600
    // 非虚继承时，有两份 A
    // 虚继承时输出：
    // sizeof(A)=4 addr=0x7ffc1571c430
    // sizeof(B)=16 addr=0x7ffc1571c410
    // sizeof(C)=16 addr=0x7ffc1571c420
    // sizeof(D)=40 addr=0x7ffc1571c410
    // 虚继承时，有一份 A，
    // B C 各有一个指针指向 A
    D d;
    cout << "sizeof(A)=" << sizeof(A) << " addr=" << hex << &(A&)d << endl;
    //cout << "sizeof(A)=" << sizeof(A) << endl;
    cout << "sizeof(B)=" << dec << sizeof(B) << " addr=" << hex << &(B&)d << endl;
    cout << "sizeof(C)=" << dec << sizeof(C) << " addr=" << hex << &(C&)d << endl;
    cout << "sizeof(D)=" << dec << sizeof(D) << " addr=" << hex << &d << endl;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
