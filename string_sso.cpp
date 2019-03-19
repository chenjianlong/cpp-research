#include <iostream>
#include <inttypes.h>
#include <cstring>

using namespace std;

class string_sso
{
public:
    string_sso(): data_(_M_local_buf) {
        set_length(0);
    }

    string_sso(const string_sso& str): data_(_M_local_buf) {
        construct(str.data_, str.data_ + str.len_);
    }

    string_sso(const char* s, size_t n = -1): data_(_M_local_buf) {
        if (n == -1)
            n = strlen(s);

        construct(s, s + n);
    }

    ~string_sso() {
        dispose();
    }

    const char* c_str() const {
        return data_;
    }

    const char& operator[](size_t i) const {
        return data_[i];
    }

    char& operator[](size_t i) {
        return data_[i];
    }

private:
    void dispose() {
        if (data_ != _M_local_buf) {
            delete [] data_;
        }
    }

    void construct(const char *beg, const char *end) {
        size_t capacity = _S_local_capacity;
        if ((end - beg) > _S_local_capacity) {
            dispose();
            capacity = (end - beg) + 1;
            data_ = new char[capacity]();
        }

        int len = 0;
        while (beg != end) {
            data_[len++] = *beg++;
        }

        set_length(len);
    }

    void set_length(size_t n) {
        len_ = n;
        data_[n] = '\0';
    }

    mutable char* data_;
    size_t len_;

    enum { _S_local_capacity = 15 / sizeof(char) };
    union {
        char _M_local_buf[_S_local_capacity + 1];
        size_t _M_allocated_capacity;
    };

};

ostream& operator<<(ostream& os, const string_sso &s)
{
    os << s.c_str();
    return os;
}

int main(int, char *[])
{
    string_sso s("hello world");
    string_sso s2(s);
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
    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
