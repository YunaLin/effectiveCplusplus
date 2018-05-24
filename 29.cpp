// 条款29:避免返回内部数据的句柄
// 指针并不是返回内部数据句柄的唯一途径，引用也很容易被滥用．
// 对于const成员函数来说，返回句柄是不明智的，因为它会破坏数据抽象

class String {
    private:
    char* data;
    public:
    String(const char* value);
    ~String();
    operator char*() const;
    // 这个函数可以修改const对象的内部数据，是引用返回句柄导致的
    // 解决方案：使函数不是const或者是重写函数不返回句柄
    char& operator[](int index) const {
        return data[index];
    }
};

const String str("Hello World");

// 像下面这样的实现返回了句柄，会破坏数据抽象
inline String::operator char*() const {
    return data;
}

char *p = str;
// 这个时候任何对p所指向的内存的修改都使得str的有效值发生变化

// 安全的实现如下：因为返回的是对象数据成员的拷贝，所以不会改变原来的数据，但是执行速度比较慢
inline String::operator char *() const {
    char *copy = new char[strlen(data) + 1];
    strcpy(copy, data);
    return copy;
}

//　快而且安全的做法是:让函数返回一个指向const char的指针
inline String::operator const char* () const {
    return data;
}

// 句柄就像是悬浮的指针，所以不管是const对象还是非const对象都要避免返回句柄