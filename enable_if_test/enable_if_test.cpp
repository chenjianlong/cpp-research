#include <iostream>
#include <new>
#include <string>
#include <type_traits>
#include <ostream>

using namespace std;

class Widget
{
public:
    virtual void show() const {
        cout << "Widget::show" << endl;
    }
};

template<class T>
typename std::enable_if<std::is_base_of<Widget, T>::value>::type
show_message(const T& t)
{
    cout << "show_message Widget" << endl;
    t.show();
}

// (1)
template<class T>
typename std::enable_if<!std::is_base_of<Widget, T>::value>::type
show_message(const T& t)
{
    cout << "show_message not Widget" << endl;
}

int main(int argc, char *argv[])
{
    class Widget w;
    show_message(w);

    // (2) the follow code is compile error!
    int i;
    show_message(i);

    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
