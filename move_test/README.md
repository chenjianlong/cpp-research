# std::move 测试

## 当参数为含有 const，std::move 结果为 const XXX&&

```
begin copy w1 to a
Widget default constructor, this=0x7fff67c02e75
Widget copy constructor, this=0x7fff67c02e77
Widget copy constructor, this=0x7fff67c02e76
Annotation(const Widget) constructor
Widget destructor, this=0x7fff67c02e77
end copy w1 to a
Annotation destructor
Widget destructor, this=0x7fff67c02e76
Widget destructor, this=0x7fff67c02e75
begin move w1 to a
Widget default constructor, this=0x7fff67c02e75
Widget move constructor, this=0x7fff67c02e77
Widget copy constructor, this=0x7fff67c02e76
Annotation(const Widget) constructor
Widget destructor, this=0x7fff67c02e77
end move w1 to a
Annotation destructor
Widget destructor, this=0x7fff67c02e76
Widget destructor, this=0x7fff67c02e75
```

## 将 （1）注释，(2) 反注释

```
begin copy w1 to a
Widget default constructor, this=0x7ffd81199ab5
Widget copy constructor, this=0x7ffd81199ab7
Widget move constructor, this=0x7ffd81199ab6
Annotation(const Widget) constructor
Widget destructor, this=0x7ffd81199ab7
end copy w1 to a
Annotation destructor
Widget destructor, this=0x7ffd81199ab6
Widget destructor, this=0x7ffd81199ab5
begin move w1 to a
Widget default constructor, this=0x7ffd81199ab5
Widget move constructor, this=0x7ffd81199ab7
Widget move constructor, this=0x7ffd81199ab6
Annotation(const Widget) constructor
Widget destructor, this=0x7ffd81199ab7
end move w1 to a
Annotation destructor
Widget destructor, this=0x7ffd81199ab6
Widget destructor, this=0x7ffd81199ab5
```