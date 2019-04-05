#include <fstream>
#include <list>
#include <iostream>
#include <iterator>

using namespace std;

int main(int, char *[])
{
    ifstream dataFile("ints.dat");
    // Effective STL item 6
    // 当 istream_iterator(dataFile) 的圆括号去掉时，data 会被解析为一个函数声明
    // 这是因为 C++ 会尽可能地解释为函数声明
    list<int> data((istream_iterator<int>(dataFile)), istream_iterator<int>());
    for (list<int>::const_iterator i = data.begin(); i != data.end(); ++i) {
        cout << *i << endl;
    }

    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
