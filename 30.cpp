// 条款30:避免这样的成员函数，其返回值是指向成员的非const指针或引用，但成员的访问级比这个函数要低
// 当成员函数返回private或者是protected数据成员的引用的时候，就破坏了数据的抽象特性
// 当返回指针也是一样的，但是指针还有一个需要考虑的是指针可以是函数指针

class Address {};
class Person {
    private:
    Address address;
    public:
    Address& personAddress() {
        return address;
    }
    ......
};
Person John(...);
Address& addr = John.personAddress();
// 这个时候addr成为了对象的一个别名，利用它可以随意的修改数据成员

// 返回较低级别的成员函数的指针的例子如下：
typedef void (Person::*PPMF)();
class Person {
    public:
    static PPMF verificationFunc() {
        return &Person::verifyAddress;
    }
    private:
    Address address;
    void verifyAddress() {}
};

PPMF pmf = John.verificationFunc();
(John.*pmf)(); // 等同于调用John.verifyAddress();

// 如果真的要返回引用或者是指针，可以返回const对象的引用或指针