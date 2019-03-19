#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    Node(string& name, int val): name_(name), val_(val) {
    }

public:
    string &name_;
    int val_;
};

int main(int, char *[])
{
    string name("Hello 1");
    Node n1(name, 3);

    string name2("Hello 2");
    Node n2(name2, 4);

    Node n3(n1);
    cout << n3.name_ << endl;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
