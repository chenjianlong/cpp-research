## 摘要

* [Effective Modern C++ item 24 通用引用](universal_reference)
* [Effective Modern C++ item 23 std::move](move_test)
* [Effective Modern C++ item 22 pImpl idiom](pimpl_idiom)
* [enable_if 使用思考](enable_if_test)
* [auto_ptr 复制后原指针为空，unique_ptr 不允许复制，支持移动](copy_auto_ptr)
* [Effective Modern C++ item 3](decltype_auto)
* [Effective Modern C++ item 6](auto_with_proxy)
* [Effective Modern C++ item 7](parenthesis_and_braces_construct)
* [Effective Modern C++ item 8](prefer_nullptr)

* More Effective C++ item 33
    * pure virtual destructor 必须有实现
    * 将函数声明为纯虚函数，并非暗示它没有实现码，而是意味着：
        * 目前这个 class 是抽象的
        * 任何集成此 class 的具体类，都必须将该纯虚函数重新声明为一个正常的虚函数

* libstdc++v3 bits/stl\_iterator.h 有 inserter back\_inserter 等的实现

* unary\_function 之类的辅助类在 C++11 中已经被标记为过期，已经在 C++17 中移除
    * 代码在 libstdc++v3 bits/stl\_function.h

* Effective STL item 10
    * C++ 的标准说，STL 的实现可以假定所有属于同一种类型的 allocator 对象都是等价的，并且互相比较的结果总是相等的
    * Allocator&lt;T&gt; 只能用于分配 T 类型的内存
    * 对于 list 和 map 等基于节点的容器，假设 list 的节点是 ListNode，这个节点的内存分配器是通过 Allocator&lt;T&gt;::rebind&lt;ListNode&gt; 获得

* Effective STL item 18
    * vector&lt;bool&gt; 是一个特化版本的 vector，它并不是存储了 bool 类型的数组
    * 示例代码：bool\_vector.cpp

* Effective STL item 28：正确理解 reverse\_iterator 的 base() 成员函数所产生的 iterator 的用法
    * 示例代码：reverse\_iterator\_to\_iterator.cpp
