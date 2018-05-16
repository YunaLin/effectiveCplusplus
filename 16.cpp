// 条款16:让operator=中对所有数据成员赋值
template <class T>
class NamedPtr {
    private:
    T* ptr;
    string name;
    public:
    NamedPtr(const string& str, T* initPtr);
    NamedPtr& operator=(const NamedPtr& other);
};

template <class T>
NamedPtr::NamedPtr(const string& str, T* initPtr):ptr(initPtr),name(str) {}

template <class T>
NamedPtr& NamedPtr::operator=(const NamedPtr& other) {
    if (this == &other) return *this;
    this.name = other.name;
    // 赋的值是指针所指的值，而不是指针本身
    *ptr = *other.ptr;
    return *this;
}
// 对于派生类的operator=，不仅要对派生类本身的成员进行赋值，而且要对父类的成员进行赋值，否则是错误的
// Base::operator=(rhs);
// 在有些情况下，编译器不支持上面的语句，所以要使用static_cast<Base&>(*this) = rhs;
// 转换的是Base对象的引用，而不是Base对象本身
// 对于派生类的拷贝构造函数.要先拷贝父类，Derived(const Derived& other):Base(other),y(other.y) {}
// 其中y是派生类的成员