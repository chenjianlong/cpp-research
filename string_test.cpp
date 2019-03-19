#include <iostream>
#include <string>
#include <inttypes.h>

using namespace std;

int main(int argc, char *argv[])
{
    string s("hello world");
    string s2(s);
    cout << "s: " << s << std::hex << " &s: 0x" << (uint64_t)&s << " sizeof(s): 0x" << sizeof(s) << " addr: 0x" << (uint64_t) s.c_str() << endl;
    cout << "s: " << s << " addr: 0x" << (uint64_t) s.c_str() << endl;
    cout << "s2: " << s2 << " addr: 0x" << (uint64_t) s2.c_str() << endl;

    if (s.c_str() == s2.c_str()) {
        cout << "the string is using COW tech" << endl;
    } else {
        cout << "the string is not using COW tech" << endl;
    }

    char *p = const_cast<char*>(s.c_str());
    *p = 'w';
    cout << "s: " << s << " addr: 0x" << (uint64_t) s.c_str() << endl;
    cout << "s2: " << s2 << " addr: 0x" << (uint64_t) s2.c_str() << endl;

    string substr = s.substr(6);
    cout << "substr: " << substr << " addr: 0x" << (uint64_t) substr.c_str() << endl;
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
