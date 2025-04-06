#include <iostream>
#include <vector>

using namespace std;

// Effective Modern C++ item 3

template<typename Container, typename Index> // C++14;
auto authAndAccess1(Container& c, Index i)    // not quite correct
{
    // do auth
    return c[i]; // return type deduced from c[i]
}

template<typename Container, typename Index>            // C++14; works,
decltype(auto) authAndAccess2(Container& c, Index i)    // but still requires refinement
{
    // do auth
    return c[i];
}

template<typename Container, typename Index>            // c is now a
decltype(auto) authAndAccess3(Container&& c, Index i)   // universal reference
{
    // do auth
    return c[i];
}

template<typename Container, typename Index>            // final C++14
decltype(auto) authAndAccess4(Container&& c, Index i)   // version
{
    // do auth
    // 防止多余的拷贝 Item41 object slicing
    return std::forward<Container>(c)[i];
}

int main(int argc, char *argv[])
{
    std::vector<int> d{1,2,3,4,5};
    //authAndAccess1(d, 3) = 33; // error: lvalue required as left operand of assignment
    authAndAccess2(d, 3) = 33;
    cout << "d[3]=" << d[3] << endl;
    cout << "d[4]=" << authAndAccess4(std::move(d), 4) << endl;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
