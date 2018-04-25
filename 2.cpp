// 条款２：尽量使用iostream而不是stdio.h

// 尽管stdio.h中的scanf和printf比较快，但是他们不是类型安全的，也没有可扩展性
// scanf和printf在读写的时候需要标明读写的变量和他们的类型，但是cout和cin重载了>>，<<函数，
// 这也是为什么cout和cin比较慢的原因,对于cout，不管x是什么类型，都可以直接cout << x,但是scanf则有%d,％f,％lld,%s等等
// 另外也不要使用非标准的iostream.h

#include <iostream>
using namespace std;

int main() {
    int x = 2;
    double num = 1.002;
    string str = "Hello!Iostream!";
    cout << x << endl;
    cout << num << endl;
    cout << str << endl;
    return 0;
}