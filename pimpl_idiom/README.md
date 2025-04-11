# EMCPP item 22

* 编译报错

```
unique_ptr.h: In instantiation of ‘void std::default_delete<_Tp>::operator()(_Tp*) const [with _Tp = Widget::Impl]’:
unique_ptr.h:263:17:   required from ‘std::unique_ptr<_Tp, _Dp>::~unique_ptr() [with _Tp = Widget::Impl; _Dp = std::default_delete<Widget::Impl>]’
pimpl_idiom/widget.h:3:7:   required from here
unique_ptr.h:76:22: error: invalid application of ‘sizeof’ to incomplete type ‘Widget::Impl’
  static_assert(sizeof(_Tp)>0,
                      ^
CMakeFiles/pimpl_idiom.dir/build.make:94: recipe for target 'CMakeFiles/pimpl_idiom.dir/main.cpp.o' failed
make[2]: *** [CMakeFiles/pimpl_idiom.dir/main.cpp.o] Error 1
CMakeFiles/Makefile2:94: recipe for target 'CMakeFiles/pimpl_idiom.dir/all' failed
make[1]: *** [CMakeFiles/pimpl_idiom.dir/all] Error 2
Makefile:148: recipe for target 'all' failed
make: *** [all] Error 2
```

* 把 widget.h 和 widget.cpp 中 (1) 中的代码反注释即可编译通过