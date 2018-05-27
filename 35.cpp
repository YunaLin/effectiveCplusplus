// 条款35:使公有继承体现＂是一个＂的含义
class Bird { ... };
class FlyingBird:public Bird {
    public:
    virtual void fly();
    ...
};
class NoFlyingBird:public Bird {
    ...
};
class Penguin:public NoFlyingBird {
    ...
};
// 所有的鸟都会飞，企鹅是鸟，企鹅不会飞
// 在C++中，公有继承：对基类对象适用的任何东西，也适用于派生类
// 但是正方形虽然是矩形的一种，但是适用于矩形规则并不一定适用于正方形
