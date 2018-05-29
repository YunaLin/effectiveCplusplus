// 条款42:明智地使用私有继承
// 如果两个类之间的继承关系为私有，一般编译器不会将派生类对象转换为基类对象
// 如果让D私有继承B,只是想要利用B已经存在的某些代码，而不是两个类在概念上有什么关系
// 尽可能地使用composition,必须时才选用私有继承
class Person {...};
class Student:private Person {
    ...
};
void dance(const Person& p) {
    cout << "dancing" << endl;
}
Person p;
Student s;
dance(p);
dance(s); // 如果是共有继承的话，这里没有错误，但是是私有继承的话错误