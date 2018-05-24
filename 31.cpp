// 条款31:千万不要返回局部对象的引用，也不要返回对象内部用new初始化的指针的引用
// 因为局部对象的生命周期在该函数体返回的时候已经结束了，但是如果返回一个引用，引用只是一个别名，但是实际的局部对象已经不存在了
// 这个条款可以参考前面的条款23,在什么时候不能够使用引用
inline const Rational& operator*(const Rational& lhs, const Rational& rhs) {
    Rational result(lhs.n* rhs.n, lhs.d*rhs.d);
    return result;
}
// 返回的是应用，但是实际上局部变量已经不存在了
// 可以用new创建一个新的对象来解决这个问题，因为new的空间分配在内存上面，必须由程序员进行释放
// 但是事实是下面的这个做法解决了问题，但是很可能出现内存泄露
inline const Rational& operator*(const Rational& lhs, const Rational& rhs) {
    Rational *result = new Rational(lhs.n* rhs.n, lhs.d*rhs.d);
    return *result;
}

// 并且返回局部静态对象也会出现不正常，可以参见前面的条款，所以尽量不要返回局部对象引用，得不偿失