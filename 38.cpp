// 条款28:决不要重新定义继承而来的缺省参数值
// 虚函数是动态绑定而缺省参数值是静态绑定的
// 动态类型指的是在可以在程序运行时改变
// 如果缺省参数值被动态绑定,编译器就必须想办法为虚函数在运行时确定合适的缺省值,
// 这将比现在采用的在编译阶段确定缺省值的机制更慢更复杂。
enum ShapeColor {RED, GREEN, YELLOW};
class Shape {
    public:
    virtual void draw(ShapeColor color = RED) const = 0;
    ...
};
class Rectangle:public Shape {
    public:
    virtual void draw(ShapeColor color = GREEN) const;
    ...
};
class Circle:public Shape {
    public:
    virtual void draw(ShapeColor color) const;
    ...
};

Shape* ps;
Shape* pr = new Rectangle;  // pr和pc的静态类型都是Shape,但是动态类型是它们指向的对象，虚函数是动态绑定的
Shape* pc = new Circle;

pr->draw(); // 这个时候调用的rectangle对象的函数，但是由于color是静态绑定的，所以color是Shape对象的缺省值
// 这样就很混杂，调用的函数是一个对象，但是函数的参数缺省值却是另外一个对象
