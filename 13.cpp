// 条款13:初始化列表中成员列出的顺序和他们在类中声名的顺序相同
template <class T>
class Array {
    public:
    Array(int low, int high);
    private:
    int size;
    int lbound;
    int hbound;
    vector<T> data;
};
// 这里的data(size)调用了vector的构造函数
// 因为析构函数和构造函数对对象成员的处理总是相反的，所以如果要用初始化列表中的成员顺序作为析构的顺序的话
// 需要跟踪顺序的开销，所以同一类型的所有对象在构造和析构的过程中对成员的处理顺序相同，而不管初始化列表的顺序
// 基类的成员必须在子类的成员之前进行初始化
// 静态成员不需要遵守这个规则
template <class T>
Array::Array(int low, int high):size(high - low + 1),lbound(low),hbound(high),data(size) {}