// 条款34:将文件间的编译依赖性降到最低
// 当改动的是类的实现而不是接口的时候重新编译生成将带来严重的开销
// 寻找一种方法：使得当类的接口改变的时候才需要进行重新编译
#include <iostream>
#include 'date.h'
#include 'address.h'
#include 'country.h'
// 当引入这些头文件的时候，Person.h就和这些头文件建立了编译依赖关系
// 当任意一个类改变了他的实现，Person就要重新进行编译
using namespace std;

class Person {
    public:
    Person(const string& name, const Date& birthday, const Address& addr, const Country& country);
    virtual ~Person();
    ......
    string name() const;
    string birthDate() const;
    string address() const;
    string nationality() const;
    private:
    string name_;
    Data birthday_;
    Address address_;
    Country country_;
};

// 将类的实现细节和类的定义分开，这样就能降低编译依赖性
// 如果有可能，尽量让头文件不要依赖于别的文件，如果不可能，就借助于类的声明，不要依靠类的定义．

// 在Person类的头文件中只放下面这些东西
// 不要再添加#include,除非无法通过编译
// 让使用这个头文件的用户自己去包含其他的头文件
// 下面这样的类被成为句柄类或者是信封类
// 另一种方式就是使用纯虚函数来实现接口，这种在之前的学习中用的比较多
class string;
class Data;
class Address;
class Country;
// 此处只是类的提前声明
class PersonImpl;

class Person {
    private:
    PersoImpl* impl; // 指向具体的实现类．所以在这里看不到Person类的实现细节
    public:
    Person(const string& name, const Date& birthday, const Address& addr, const Country& country);
    virtual ~Person();
    ......
    string name() const;
    string birthDate() const;
    string address() const;
    string nationality() const;
};

// 如果可以使用对象的引用或指针就要避免使用对象本身