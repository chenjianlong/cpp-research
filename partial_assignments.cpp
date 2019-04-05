#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    string name;
};

class Chicken: public Animal
{
public:
    int age;
};

int main(int, char*[])
{
    Chicken c1, c2;
    c1.name = "XY";
    c1.age = 5;
    c2.name = "YY";
    c2.age = 6;

    Animal *p1 = &c1;
    Animal *p2 = &c2;

    *p1 = *p2;
    cout << "c1, name=" << c1.name << " age=" << c1.age << endl;
    cout << "c2, name=" << c2.name << " age=" << c2.age << endl;

    // 输出：
    // c1, name=YY age=5
    // c2, name=YY age=6
    // 以上代码会导致部分赋值，详见 More Effective C++ item 33
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
