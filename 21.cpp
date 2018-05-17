// 条款21:尽可能使用const
// 使用const来指定一种约束
const char* p; // const数据，非const指针
char* const p; // const指针，非const数据
const char* const p; // const指针，const数据
// 根据const在*的左边还是右边，＂左定值，右定向＂
// 对返回值使用const可以提高一个函数的安全性和效率
// 仅在const方面有不同的函数可以重载
// const成员函数对const对象进行操作

// 修改一个返回值为固定类型的函数的返回值是不合法的
class String {
    private:
    char* data;
    public:
    // 用于非const对象的操作
    char& operator[](int position) {
        return data[position];
    }
    // 用于const对象的操作
    const char& operator[](int position) const {
        return data[position];
    }
};