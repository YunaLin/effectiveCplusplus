// 条款36:区分接口继承和实现继承
// 定义纯虚函数的目的：使得派生类仅仅只是继承基类的接口
// 但是在抽象类中，无法对该纯虚函数进行一个准确的定义，因为在每一个派生类中该函数的定义都不一样
// 简单虚函数的目的在于：使派生类继承函数的接口和缺省实现
// 非虚函数的目的在于：使派生类继承函数的接口和强制性实现
// 几乎任何一个作为基类的都有虚函数
class Shape {
    public:
    virtual void draw() const = 0;
    virtual void error(const string& msg);
    int ObjectId() const;
    ...
};

class Rectangle:public Shape {
    ...
};
class Ellipse:public Shape {
    ...
};
// 你必须提供一个draw函数，但我不知道你会怎样实现他

class Airplane {
    public:
    virtual void fly(const Airport& destination) = 0;
    protected:
    virtual void defaultFly(const Airport& destination) {
        飞往某一目的地的缺省代码
    } 
};

class ModelA:public Airplane {
    public:
    virtual void fly(const Airport& destination) {
        defaultFly(destination);
    }
};

class ModelB:public Airplane {
    public:
    virtual void fly(const Airport& destination) {
        defaultFly(destination);
    }
};

class ModelC:public Airplane {
    public:
    virtual void fly(const Airport& destination) {
        ModelC飞往某一个目的地的代码实现
    }
};