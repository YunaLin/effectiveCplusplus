// 条款18:争取使类的接口完整且最小
// 典型的接口里只有函数存在，而没有数据成员
// 完整的接口：允许用户做他们想做的任何合理的接口
// 最小的接口：函数尽可能少，每两个函数没有重叠功能的接口
template <class T>
class Array {
    private:
    int lbound;
    int hbound;
    vector<T> datas;
    boundsCheckingStatus checkingBounds;
    public:
    enum boundsCheckingStatus {
        NO_CHECK_BOUNDS = 0,
        CHECK_BOUNDS = 1
    };
    Array(int low, int high, boundsCheckingStatus = NO_CHECK_BOUNDS);
    Array(const Array& rhs);
    ~Array();
    Array& operator=(const Array& rhs);
    // 返回值不同很重要
    T& operator[](int index);
    const T& operator[](int index) const;
    // 下面这两个函数是为了能够对数组进行遍历
    int lowBound() const;
    int highBound() const;
    // 还需要一个友元函数operator<<
    // 在外面定义的时候不需要加friend
    // 友元函数在所有实际应用中都是类的接口的一部分，因此友元函数影响类的接口的完整性和最小性
    friend ostream& operator<<(ostream& out, const Array& rhs);
    friend istream& operator>>(istream& in, Array& rhs);
};