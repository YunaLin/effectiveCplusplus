// 条款27:如果不想使用隐式生成的函数就要显示的禁止他
// 例如：如何进行Array中对象之间的赋值操作
// double val[100]; double val2[100]; val=val2;

// operator=如果不声明的话，编译器会自动生成一个，所以显式的声明一个成员函数
// 就防止了编译器去自动生成他的版本，是函数为private,就防止了别人去非法调用他
// 但是因为成员函数和友元函数依然可以调用private里面的函数，所以可以只声明operator=但是不定义他
// 当成员函数去调用operator=的时候链接器就会报错

template <class T>
class Array {
    private:
    ...
    // 注意：不要定义这个函数！
    Array& operator=(const Array& rhs); 
    public:
    ...
};

// 这个方法适用于所有系统会自动生成的函数