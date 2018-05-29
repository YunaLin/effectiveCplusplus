// 条款41：区分继承和模板
// 模板类的特点：行为不依赖类型
// 当对象的类型不影响类中函数的行为时,就要使用模板来生成这样一组类。
// 当对象的类型影响类中函数的行为时,就要使用继承来得到这样一组类。

template <class T>
class Stack {
    private:
    struct StackNode {
        T data;
        StackNode* next;
        StackNode(const T& d, StackNode* n):data(d),next(n) {}  
    };
    StackNode* top;
    Stack(const Stack& rhs);
    Stack& operator=(const Stack& rhs);
    public:
    Stack();
    ~Stack();
    void push(const T& object);
    T pop();
    bool empty() const;
};

Stack::Stack():top(0) {}
template <class T>
void Stack::push(const T& object) {
    top = new StackNode(object, top);
}
template <class T>
T Stack::pop() {
    StackNode* temp = top;
    top = top->next;
    T data = temp->data;
    delete temp;
    return data;
}

template <class T>
Stack::~Stack() {
    while (top) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

bool Stack::empty() const {
    return top == 0;
}