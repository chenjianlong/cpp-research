#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, string> names;

string name_from_idx(int idx)
{
    if (names.count(idx)) {
        return names[idx];
    } else {
        return "";
    }
}

class Person {
public:
    template<typename T>
    explicit Person(T&& n)        // perfect forwarding ctor;
        : name(std::forward<T>(n)) { // initializes data member
        cout << "Person constructor std::forward" << endl;
    }

    explicit Person(int idx) // int ctor
    : name(name_from_idx(idx)) {
        cout << "Person(int) constructor, idx=" << idx << endl;
    }

private:
    std::string name;
};

int main(int argc, char *argv[])
{
    Person p("hello");
    Person p2(3);
    // Person p3(static_cast<short>(3)); // error match std::forward version
    // Person p4(p); // error match std::forward version


    const Person p5(5);
    Person p6(p5); // constructor by default copy constructor version generate by compiler
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
