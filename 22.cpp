// 条款22:尽可能使用传引用而不用传值
// 通过值来传递一个对象的具体含义是：由这个对象的类的拷贝构造函数定义的
// 通过引用的一个优点是：没有额外的拷贝构造函数和额外的析构函数，并且避免了所谓的＂切割问题＂
// 切割问题指的是：派生类对象作为基类对象进行传递，但是为了不能修改，需要将引用加上const
// 引用几乎都是通过指针实现的，因此如果对象很小，传值会比传引用更加高效，并且有的时候不能传引用
class Window {
    public:
    string getName() const;
    virtual void display() const;
};

class WindowWithScrollBar() {
    public:
    virtual void display() const;
};

// 传入的参数如果是引用的话，可以解决切割问题
void printNameAndDisplay(const Window& w) {
    cout << w.getName() << endl;
    w.display();
}

// 传入的参数值是引用，同时返回的也是引用
// 如果传入和返回的是值，会调用大量的构造函数和析构函数
const Student& returnStudent(const Student& s) {
    return s;
}