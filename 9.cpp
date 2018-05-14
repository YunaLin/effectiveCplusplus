#include <iostream>
using namespace std;

void f() {
    cout << "this is a function in global" << endl;
}
// 解决类内部的函数隐藏掉全局函数的方法
// 1. 再定义一个与全局New函数一样的函数
// 2. 新定义的new函数中添加的参数使用缺省形式
// void* operator new(size_t size, new_handler p = 0);
class X {
    public:
    void f() {
        cout << "this is function in a class" << endl;
    }
    // 还需要定义一个与标准的new函数相同的函数
    // 类内部的成员函数会隐藏掉全局函数
    static void* operator new(size_t size, new_handler p) {}
    static void* operator new(size_t size) {
        return ::operator new(size);
    }
};

int main() {
    X x;
    f();
    x.f();
    new_handler globalHandler = set_new_handler(0);
    set_new_handler(globalHandler);
    X* p1 = new (globalHandler)X;
    X* p2 = new X;
    return 0;
}