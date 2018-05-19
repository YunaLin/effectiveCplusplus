// 条款23:必须返回一个对象时不要试图返回一个引用
// 避免传递一个并不存在的对象的引用
class Rational {
    private:
    int n, d;
    public:
    Rational(int numerator = 0, int deminator = 1):n(numerator), d(deminator) {}
    friend const Rational operator*(const Rational& lhs, const Rational& rhs);
};

// 这里必须返回值，因为引用只是一个别名
inline const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.n*rhs.n, lhs.d*rhs.d);
}
// 作者列举了很多尝试返回引用的错误做法，并且分析很到位，具体参见书里内容