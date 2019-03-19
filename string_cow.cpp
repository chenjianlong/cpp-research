#include <iostream>
#include <inttypes.h>
#include <cstring>

using namespace std;

class string_cow
{
public:
    string_cow(): data_(_S_empty_rep().refdata()) {
    }

    string_cow(const string_cow& str): data_(str.rep()->grab()) {
    }

    string_cow(const char* s): data_(_S_construct(s, s + strlen(s))) {
    }

    string_cow(const char* s, size_t n): data_(_S_construct(s, s + n)) {
    }

    ~string_cow() {
        rep()->dispose();
    }

    const char* c_str() const {
        return data_;
    }

    size_t size() const {
        return rep()->_M_length;
    }

    const char& operator[](size_t pos) const {
        return data_[pos];
    }

    char& operator[](size_t pos) {
        leak();
        return data_[pos];
    }

private:
    char* _S_construct(const char* beg, const char *end) {
        if (beg == end)
            return _S_empty_rep().refdata();

        size_t n = end - beg;
        _Rep* r = _Rep::_S_create(n);
        memcpy(r->refdata(), beg, n);

        r->set_length_and_sharable(n);
        return r->refdata();
    }

    void leak() {
        if (!rep()->is_leaked()) {
            if (rep() == &_S_empty_rep()) {
                return ;
            }

            if (rep()->is_shared()) {
                _Rep* r = _Rep::_S_create(this->size());
                memcpy(r->refdata(), data_, this->size());
            }

            rep()->set_leaked();
        }
    }

    struct _Rep_base {
        size_t _M_length;
        size_t _M_capacity;
        int _M_refcount;
    };

    struct _Rep: _Rep_base {
        // The following storage is init'd to 0 by the linker, resulting
        // (carefully) in an empty string with one reference.
        static size_t _S_empty_rep_storage[];

        static _Rep& _S_empty_rep() {
            // NB: Mild hack to avoid strict-aliasing warnings.  Note that
            // _S_empty_rep_storage is never modified and the punning should
            // be reasonably safe in this case.
            void* p = reinterpret_cast<void*>(&_S_empty_rep_storage);
            return *reinterpret_cast<_Rep*>(p);
        }

        bool is_leaked() const {
            return this->_M_refcount < 0;
        }

        bool is_shared() const {
            return this->_M_refcount > 0;
        }

        void set_leaked() {
            this->_M_refcount = -1;
        }

        void set_sharable() {
            this->_M_refcount = 0;
        }

        void set_length_and_sharable(size_t n) {
            if (this != &_S_empty_rep() ) {
                this->set_sharable();  // One reference.
                this->_M_length = n;
                this->refdata()[n] = '\0';
            }
        }

        char* refdata() {
            return reinterpret_cast<char*>(this + 1);
        }

        char* grab() {
          return !is_leaked()
                  ? refcopy() : clone();
        }

        static _Rep* _S_create(size_t n) {
            size_t size = n + sizeof(_Rep) + 1;
            void* place = new char[size]();
            _Rep *p = new (place) _Rep;
            p->_M_capacity = n;
            return p;
        }

        void dispose() {
            if (this != &_S_empty_rep()) {
                if (_M_refcount-- <= 0) {
                    delete [] reinterpret_cast<char*>(this);
                }
            }
        }

        char* refcopy() {
            this->_M_refcount++;
            return refdata();
        }

        char* clone() {
            _Rep *r = _S_create(this->_M_capacity);
            if (this->_M_length)
                memcpy(r->refdata(), refdata(), this->_M_length);

            r->set_length_and_sharable(this->_M_length);
            return r->refdata();
        }
    };

    static _Rep& _S_empty_rep() {
        return _Rep::_S_empty_rep();
    }

    _Rep* rep() const {
      return &((reinterpret_cast<_Rep*> (data_))[-1]);
    }

private:
    char *data_;
};

size_t string_cow::_Rep::_S_empty_rep_storage[
    (sizeof(_Rep_base) + sizeof(char) + sizeof(size_t) - 1) /
      sizeof(size_t)];

ostream& operator<<(ostream& os, string_cow& str)
{
    os << str.c_str();
    return os;
}

int main(int, char *[])
{
    string_cow s("hello world");
    string_cow s2(s);
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
