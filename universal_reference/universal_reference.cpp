#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void f(std::vector<T>&& params) // params is rvalue reference, not universal references
{
}

int main(int argc, char *argv[])
{
    vector<int> v;
    // error: cannot bind rvalue reference of type ‘std::vector<int>&&’ to lvalue of type ‘std::vector<int>’
    f(v);
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
