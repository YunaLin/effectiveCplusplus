// 条款17:在operator=中检查给自己赋值的情况

// 只要别名有可能出现，就必须在写代码的时候进行处理
A& A::operator=(const A& other) {
    if (this == &other) return *this;
    ...
}