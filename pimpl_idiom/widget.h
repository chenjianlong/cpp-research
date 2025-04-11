#include <memory>

class Widget {
public:
    Widget();

    // (1)
    // ~Widget();

private:
    struct Impl; 
    std::unique_ptr<Impl> pImpl;
};