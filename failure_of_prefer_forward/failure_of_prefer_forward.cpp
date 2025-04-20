#include <iostream>
#include <vector>

using namespace std;

class Widget {
public:
    static const std::size_t MinVals = 28; // MinVals' declaration
};

// (1)
// const std::size_t Widget::MinVals;

void f(std::size_t val)
{
    cout << "val: " << val << endl;
}

template<typename T>
void fwd(T&& val)
{
    f(std::forward<T>(val));
}

int main(int argc, char *argv[])
{
    std::vector<int> widgetData;
    widgetData.reserve(Widget::MinVals); // use of MinVals

    f(Widget::MinVals);
    fwd(Widget::MinVals); // link error, uncomment (1) to fix link error
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
