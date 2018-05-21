// 条款26:当心潜在的二义性
void f(int);
void f(char);
double d = 2.2222;
f(d); // 出现二义性，因为d可以转换成int和char,但是编译器不会在这两者中进行一个选择
// 可以通过显式类型转换来解决这个问题
f(static_cast<int>(d));
f(static_cast<char>(d));

// 多继承充满了潜在二义性的可能，最常发生的一种情况是当一个派生类从多个基类继承相同的成员名时
class Base1 {
    public:
    void f();
};
class Base2 {
    public:
    int f();
};
class Derived:public Base1, public Base2 {
}; // 没有声明f函数

Derived d;
d.f(); // 出现二义性
// 即使使用下面的表达式，也一样会出现二义性
int num = d.f();
// 正确的调用方法是：
d.Base1::f();
d.Base2::f();
