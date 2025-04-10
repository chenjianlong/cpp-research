#include <memory>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    auto_ptr<int> p1(new int(34));
    auto_ptr<int> p2 = p1;

    cout << "p1 is empty: " << (p1.get() ? "false" : "true") << endl;
    cout << "p2 is empty: " << (p2.get() ? "false" : "true") << endl;

    unique_ptr<int> p3(new int(35));
    // unique_ptr<int> p4 = p3; // compile error copy operator is delete
    unique_ptr<int> p5 = std::move(p3);

    cout << "p3 is empty: " << (p3.get() ? "false" : "true") << endl;
    cout << "p5 is empty: " << (p5.get() ? "false" : "true") << endl;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
