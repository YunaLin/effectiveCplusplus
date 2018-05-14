// 条款10: 如果写了operator new就要同时写operator delete
// 创建缺省的operator new和operator delete函数可以提高灵活性和效率
// 可以在自己实现的operator new和operator delete之间互相传递信息
// operator new可以在返回的内存里预先附带一些额外信息，来指明被分配的内存块的大小
#include <iostream>
using namespace std;
// 引起内存泄露的原因在于内存分配后指向内存的指针丢失了
// 可以使用内存池来进行内存的管理

// 表示一个飞机对象
class AirplaneRep {...};

class Pool {
    public:
    Pool(size_t n) {}
    void alloc(size_t n) {}
    void free(void* p size_t n) {}
    ~Pool() {}
};

class Airplane {
    public:
    static void* operator new(size_t size);
    static void operator delete(void* deadObject, size_t size);
    private:
    union {
        // 用于被使用的对象
        AirplaneRep* rep;
        // 用于自由链表中没被使用的对象
        Airplane* next;
    };
    static const int BLOCK_SIZE;
    static Airplane* headOfFreeList;
    static Pool memPool;
};

// inline void* Airplane::operator new(size_t size) {
//     return memPool.alloc(size);
// }

void* Airplane::operator new(size_t size) {
    if (size != sizeof(Airplane))
        return ::operator new(size);
    Airplane* p = headOfFreeList;
    if (p) {
        headOfFreeList = p->next;
    } else {
        Airplane* newBlock = 
        static_cast<Airplane*>(::operator new(BLOCK_SIZE*sizeof(Airplane)));
        for (int i = 1; i < BLOCK_SIZE - 1; ++i) {
            newBlock[i].next = &newBlock[i + 1];
        }
        newBlock[BLOCK_SIZE - 1].next = 0;
        p = newBlock;
        headOfFreeList = &newBlock[1];
    }
    return p;
}
// inline void Airplane::operator delete(void* deadObject, size_t size) {
//     memPool.free(deadObject, size);
// }
void Airplane::operator delete(void* deadObject, size_t size) {
    if (deadObject == 0) return;
    if (size != sizeof(Airplane)) {
        ::operator delete(deadObject);
        return;
    }
    Airplane* carcass = static_cast<Airplane*>(deadObject);
    carcass->next = headOfFreeList;
    headOfFreeList = carcass;
}
// 静态成员的初始值都被缺省设置为０，所以这里不需要将headOfFreeList设置为null
Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;
// Pool Airplane::memPool(sizeof(Airplane));

int main() {
    Airplane * p = new Airplane;
    delete p;
    return 0;
}