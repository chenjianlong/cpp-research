#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Widget {
public:
    Widget() {
        cout << "Widget()" << endl;
    }

    Widget(int i, bool b): i_(i), b_(b) {
        cout << "Widget(int, bool)" << endl;
    }

    Widget(int i, double d): i_(i), d_(d) {
        cout << "Widget(int, double)" << endl;
    }

    Widget(std::initializer_list<bool> il) {
        cout << "Widget(std::initializer_list<bool>)" << endl;
        if (il.size()) {
            b_ = *il.begin();
        }
    }

private:
    int i_ = 0;
    double d_ = 0.0;
    bool b_ = false;
};

class Widget2 {
public:
    Widget2(int i, bool b): i_(i), b_(b) {
        cout << "Widget2(int, bool)" << endl;
    }

    Widget2(int i, double d): i_(i), d_(d) {
        cout << "Widget2(int, double)" << endl;
    }

    Widget2(std::initializer_list<std::string> il) {
        cout << "Widget2(std::initializer_list<std::string>)" << endl;
    }

private:
    int i_ = 0;
    double d_ = 0.0;
    bool b_ = false;
};

int main(int argc, char *argv[])
{
    Widget w1(10, 5.0);
    // Widget w2{10, 5.0}; // error! requires narrowing conversions

    Widget2 w3(10, true);
    Widget2 w4{10, true};

    Widget2 w5(10, 5.0);
    Widget2 w6{10, 5.0};

    cout << "before w7" << endl;
    Widget w7;
    cout << "before w8" << endl;
    Widget w8();
    cout << "before w9" << endl;
    Widget w9{};
    cout << "before w10" << endl;
    Widget w10({});
    cout << "before w11" << endl;
    Widget w11{{}};

    // 对于有 std::initializer_list 的类来说，使用小括号还是大括号进行初始化有时候结果会截然不同
    vector<int> v1(10,20);     // vector 有10个值，每个值都是 20
    vector<int> v2{10,20};     // vector 有2个值，分别是 10、20

    cout << "vector<int> v1(10, 20) size: " << v1.size() << endl;
    cout << "[ ";
    bool first = true;
    for (const auto&i : v1) {
        if (!first) {
            cout << ", ";
        } else {
            first = false;
        }

        cout << i;
    }

    cout << " ]" << endl;

    cout << "vector<int> v2{10, 20} size: " << v2.size() << endl;
    cout << "[ ";
    first = true;
    for (const auto&i : v2) {
        if (!first) {
            cout << ", ";
        } else {
            first = false;
        }

        cout << i;
    }

    cout << " ]" << endl;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
