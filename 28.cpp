// 条款28:划分全局名字空间
// 名字空间带来的好处：潜在的二义性不会造成错误，从多个不同的名字空间引入同一变量名字不会出现冲突
#include <iostream>
using namespace std;

namespace name1 {
    const int num = 10;
    void f() {
        std::cout << "hello, name1" << std::endl;
    }
}
namespace name2 {
    const int num = 20;
}

int main() {
    using namespace name1;
    using namespace name2;
    std::cout << name1::num << std::endl;
    std::cout << name2::num << std::endl;
}
