#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int, char*[])
{
    vector<int> v;
    v.reserve(5);
    for (int i = 1; i <= 5; ++i) {
        v.push_back(i);
    }

    vector<int>::reverse_iterator ri = find(v.rbegin(), v.rend(), 3);
    vector<int>::iterator i = ri.base();
    v.erase(--ri.base());

    // Effective STL 28 正确理解 revser_iterator 的 base() 成员函数
    // 输出如下：
    // *ri=3 *i=4
    cout << "*ri=" << *ri << " *i=" << *i << endl;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
