// 条款6:析构函数里对指针成员调用delete

// 如果是使用了智能指针，则不需要调用delete进行释放
// 对于一个指针，如果没有分配内存要对其赋值初始null，delete一个空指针是安全的
// shared_ptr，unique_ptr,weak_ptr，需要头文件<memory>
#include <iostream>
using namespace std;

class A {
    public:
    A() {
        ptr = new int;
    }
    ~A() {
        delete ptr;
    }
    private:
    int* ptr;
};

int main() {
    A* p = new A;
    cout << p << endl;
    delete p;
    return 0;
}