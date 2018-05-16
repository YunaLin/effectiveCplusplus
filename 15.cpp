// 条款15:让operator=返回*this的引用
// 一般情况下总要让operator=的输入和返回都是类对象的引用
// 因为在连续链式赋值操作中,=的返回值会作为输入
// 但是不要返回const+对象的引用
String& String::operator=(const String& rhs) {
    ....
    //　注意不要返回rhs，一个是rhs是const String&，另一个是a="Hello"编译不通过
    return *this;
}