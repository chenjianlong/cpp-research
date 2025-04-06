#include <iostream>
#include <vector>

using namespace std;

std::vector<bool> features()
{
    return {true, true, true, true, true, true};
}

int main(int argc, char *argv[])
{
    bool highPriority = features()[5];
    cout << "highPriority=" << highPriority << endl;
    auto highPriority2 = features()[5];
    cout << "highPriority2=" << highPriority2 << endl;
    auto highPriority3 = static_cast<bool>(features()[5]);
    cout << "highPriority3=" << highPriority3 << endl;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
