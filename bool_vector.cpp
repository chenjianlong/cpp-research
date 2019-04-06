#include <iostream>
#include <vector>

using namespace std;

int main(int, char*[])
{
    // Effective STL item 18
    // vector<bool> 是一个特化版本的 vector，它并不是存储了 bool 类型的数组
    // 以下代码无法通过编译
    vector<bool> vb(10);
    bool *pb = &vb[0];
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
