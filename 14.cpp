// 确定基类有虚析构函数
// 当通过基类的指针去删除派生类的对象时，而基类又没有虚析构函数，结果将是不可确定的．
// 实际上是，派生类的析构函数将永远不会被调用
// 几乎所有的基类都包含虚函数
// 虚函数表需要维护虚函数指针，所以无故生命虚函数也是错误的，因为会占用内存
// 必须提供纯虚析构函数的定义
#include <iostream>
using namespace std;

// 如果基类的析构函数没有声明为虚函数的话,下面的代码在析构的时候numTargets变化但是numTanks没有变化
// EnemyTarget* ptr = new EnemtTank;
// delete ptr;
// 将基类的析构函数声明为虚函数，则在析构的时候会调用基类的析构函数和派生类的析构函数

class EnemyTarget {
    public:
    static size_t getNumTargets() {
        return numTargets;
    }
    EnemyTarget() {
        numTargets++;
    }
    EnemyTarget(const EnemyTarget& other) {
        numTargets++;
    }
    // 更改析构函数为虚函数
    virtual ~EnemyTarget() {
        numTargets--;
    }
    virtual bool destroy(); // 摧毁对象后返回成功
    private:
    static size_t numTargets;
};
size_t EnemyTarget::numTargets;


// 较好的一个准则：当且仅当类里至少包含一个虚函数的时候才去声明虚析构函数
// 但是当类里没有虚函数的时候，也可能出现非析构函数问题
class EnemyTank:public EnemyTarget {
    public:
    EnemyTanks() {
        numTanks++;
    }
    EnemyTanks(const EnemyTanks* other) {
        EnemyTarget(other);
    }
    ~EnemyTank() {
        numTanks--;
    }
    virtual bool destroy();
    static size_t getNumTanks() {
        return numTanks;
    }
    private:
    static size_t numTanks;
};
size_t EnemyTank::numTanks;

int main() {
    return 0;
}