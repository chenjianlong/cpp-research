#include <iostream>
#include <string>

using namespace std;

class Widget
{
public:
    Widget() {
        cout << "Widget default constructor, this="  << static_cast<void*>(this) << endl;
    }

    Widget(Widget&& other) {
        cout << "Widget move constructor, this=" << static_cast<void*>(this) << endl;
    }

    Widget(const Widget& other) {
        cout << "Widget copy constructor, this=" << static_cast<void*>(this) << endl;
    }

    ~Widget() {
        cout << "Widget destructor, this=" << static_cast<void*>(this) << endl;
    }
};

class Annotation
{
public:
    // (1)
    explicit Annotation(const Widget w): w_(std::move(w)) {
        cout << "Annotation(const Widget) constructor" << endl;
    }

    // (2)
    //explicit Annotation(Widget w): w_(std::move(w)) {
    //    cout << "Annotation(const Widget) constructor" << endl;
    //}

    ~Annotation() {
        cout << "Annotation destructor" << endl;
    }

private:
    Widget w_;
};


int main(int argc, char *argv[])
{
    {
        cout << "begin copy w1 to a" << endl;
        Widget w1;
        Annotation a(w1);
        cout << "end copy w1 to a" << endl;
    }

    {
        cout << "begin move w1 to a" << endl;
        Widget w1;
        Annotation a(std::move(w1));
        cout << "end move w1 to a" << endl;
    }

    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
