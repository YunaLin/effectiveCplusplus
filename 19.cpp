// 条款19:分清成员函数，非成员函数和友元函数
// 成员函数可以是虚拟的，但是非成员函数不行
// 只要能避免友元函数就避免，友元函数带来的麻烦往往比帮助多
// operator<<和operator>>决不能是成员函数

// 只有非成员函数对最左边的参数进行类型转换
class Rational {
    private:
    int numerator;
    int denominator;
    public:
    int getNumerator() const {
        return numerator;
    }
    int getDenominator() const {
        return denominator;
    }
    Rational(int numerator = 0, int denominator = 1):numerator(numerator),denominator(denominator) {} 
    const Rational operator*(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.getNumerator()*rhs.getNumerator(), lhs.getDenominator()*rhs.getDenominator());
    }
};