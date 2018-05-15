//　条款12:尽量使用初始化而不要在构造函数里赋值
#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class NamedPtr {
    public:
    NamedPtr(const string& initName, T* initptr);   
    string getName() {
        return name;
    }
    private:
    // 当成员变量声明为const后只能使用初始化不能用赋值的方式
    // 对名字同时声明为const和引用，就生成了一个在类外可以被修改而在类内是只读的对象
    const string& name;
    // 对与＊放在const的前面和后面：＂左定值右定向＂
    T* const ptr;
};

// 使用初始化列表：
// const和引用数据成员只能够初始化
template <class T>
NamedPtr<T>::NamedPtr(const string& initName, T* initptr):name(initName),ptr(initptr) {}
// 在构造函数里面赋值
// 先会调用一次string的缺省构造函数，然后再调用operator=函数
// 但是如果使用初始化列表的话，直接调用拷贝构造函数即可，只调用了一个成员函数
// 所以使用初始化列表的效率比较高，而且在大多情况下都适用
// NamedPtr::NamedPtr(const string& initName, T* initptr) {
//     name = initName;
//     ptr = initptr;
// }

int main() {
    string name = "hello";
    int num = 1;
    int* ptr = &num;
    NamedPtr<int> namedptr(name, ptr);
    cout << namedptr.getName() << endl;
    return 0;
}