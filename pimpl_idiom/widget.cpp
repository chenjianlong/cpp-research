#include "widget.h"
#include <string>
#include <vector>

struct Widget::Impl {
    std::string name;
    std::vector<double> data;
};

Widget::Widget()                  // per Item 21, create
: pImpl(std::make_unique<Impl>()) // std::unique_ptr
{}                                // via std::make_unique

// (1)
// Widget::~Widget() = default;