## enable_if

### 输出：

```
show_message Widget
Widget::show
```

### 把 (2) 注释代码反注释后编译出错

```
enable_if_test.cpp:40:19: error: no matching function for call to ‘show_message(int&)’
     show_message(i);
                   ^
enable_if_test.cpp:19:1: note: candidate: template<class T> typename std::enable_if<std::is_base_of<Widget, T>::value>::type show_message(const T&)
 show_message(const T& t)
 ^~~~~~~~~~~~
enable_if_test.cpp:19:1: note:   template argument deduction/substitution failed:
enable_if_test.cpp: In substitution of ‘template<class T> typename std::enable_if<std::is_base_of<Widget, T>::value>::type show_message(const T&) [with T = int]’:
enable_if_test.cpp:40:19:   required from here
enable_if_test.cpp:19:1: error: no type named ‘type’ in ‘struct std::enable_if<false, void>’
CMakeFiles/enable_if_test.dir/build.make:81: recipe for target 'xxx/enable_if_test.cpp.o' failed
make[2]: *** [CMakeFiles/enable_if_test.dir/enable_if_test.cpp.o] Error 1
CMakeFiles/Makefile2:94: recipe for target 'CMakeFiles/enable_if_test.dir/all' failed
make[1]: *** [CMakeFiles/enable_if_test.dir/all] Error 2
Makefile:148: recipe for target 'all' failed
make: *** [all] Error 2
```

### 把 (1)、(2) 注释代码反注释后输出

```
show_message Widget
Widget::show
show_message not Widget
```