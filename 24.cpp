// 条款24:在函数重载和设置缺省值之间慎重选择
// 如果可以选择一个合适的缺省值并且只是用到一种算法，就使用缺省函数，否则用函数重载
// 缺省构造函数是凭空（没有输入）构造一个对象，而拷贝构造函数是根据一个已存在的对象构造一个对象
// 如果不能找到一个合适的缺省值就要使用重载
class Natural {
    private:
    unsigned int value;
    void init(int initValue);
    void error(const string& msg);  
    public:
    Natural(int initValue);
    Natural(const Natural& rhs);
};

inline void Natural::init(int initValue) {
    value = initValue;
}
Natural::Natural(int initValue) {
    if (initValue > 0) init(initValue);
    else error("illigal initial value");
}
inline Natural::Natural(const string& rhs) {
    init(rhs.value);
}

// 因为在输入为int的构造函数中需要执行错误判断，但是在拷贝构造函数中不用，所以需要用两个不同的函数来实现，
// 这就是重载的一个例子