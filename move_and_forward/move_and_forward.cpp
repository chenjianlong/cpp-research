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

Widget return_move(Widget&& w)
{
    //(1) move constructor call
    return std::move(w);
    //(2) copy constructor call
    //return w;
}

template<typename T>
T return_forward(T&& w)
{
    return std::forward<T>(w);
}

Widget make_widget() // "Copying" version of makeWidget
{
    Widget w; // local variable
    cout << "inside make_widget" << endl;
    return w; // "copy" w into return value
    // (3)
    // return std::move(w);
}

int main(int argc, char *argv[])
{
    {
        cout << "begin return_move" << endl;
        Widget w1;
        // (4)
        //Widget w2 = return_move(w1); // error: cannot bind rvalue reference of type ‘Widget&&’ to lvalue of type ‘Widget’
        Widget w2 = return_move(std::move(w1));
        cout << "end return_move" << endl;
    }
    
    {
        cout << "begin return_forward" << endl;
        Widget w1;
        Widget w2 = return_forward(w1);
        Widget w3 = return_forward(std::move(w1));
        cout << "end return_move" << endl;
    }

    {
        cout << "begin make_widget" << endl;
        Widget w1 = make_widget();
        cout << "end make_widget" << endl;
    }

    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
