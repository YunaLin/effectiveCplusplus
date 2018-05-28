// 条款40:通过分层来体现有一个或＂用．．．来实现"
// 分层：某个类的对象作为另外一个类的数据成员，即composition,is part of的概念
class Address {...};
class PhoneNumber {...};
class Person {
    private:
    string name;
    Address addr;
    PhoneNumber phone; // 在这里Person是Address和PhoneNumber的上层
};

// 通过建立分层关系，建立了类之间的依赖关系
// 这里是实现集合，而不是标准模板库中的Set
// 如果是让Set is kind of list的话，因为list元素可以重复，但是集合不可以，所以可以通过让list is part of set来实现
template <class T>
class Set {
    private:
    list<T> rep;
    public:
    bool member(const T& item) const;
    void insert(const T& item);
    void remove(const T& item);
    int cardinality() const;
};

template <class T>
bool Set::member(const T& item) const {
    return find(rep.begin(), rep.end(), item) != rep.end();
}
void Set::insert(const T& item) {
    if (!member(item)) {
        rep.push_back(item);
    }
}
void Set::remove(const T& item) {
    list<T>::iterator it = find(rep.begin(), rep.end(), item);
    if (it != rep.end()) {
        rep.erase(it);
    }
}
int Set::cardinality() const {
    return rep.size();
}