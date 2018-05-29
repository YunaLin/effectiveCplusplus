// 条款43:明智的使用多继承
class A {
    public:
    virtual void draw() const = 0;
};
class B {
    public:
    virtual void draw() const = 0;
};

class C:public A, public B {
    public:
    void draw() {
        ....
    }
}
// 多继承的一个问题是二义性的问题，调用的时候需要指明调用的是那个类的函数
// 例外是多继承，多层继承的时候，比如下面，会导致D中有多个A的数据成员的拷贝
//     A
// ／　　　＼
// B      C
// \      /
//     D