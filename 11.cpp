// 条款11:为需要动态分配内存的类声明一个拷贝构造函数和一个赋值操作符
#include <iostream>
#include <string.h>
using namespace std;

// 如果定义拷贝构造函数和赋值操作符不切实际的话，可以在private中声明但是不定义他们，这样就阻止有人调用它们
class String {
    public:
    String(const char* str);
    ~String();
    char* getData() {
        return data;
    }
    // 声明拷贝构造函数
    String(const String& other);
    // 声明赋值操作符
    void operator=(const String& str);
    private:
    char* data;
};

String::String(const String& other) {
    *this = other;
}

void String::operator=(const String& str) {
    if (this == &str) return;
    if (str.data) {
        data = new char[strlen(str.data) + 1];
        strcpy(data,str.data);
    } else {
        data = new char[1];
        *data = '\0';
    }
}

String::String(const char* str) {
    if (str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    } else {
        data = new char[1];
        *data = '\0';
    }
}

inline String::~String() {
    delete []data;
}

int main() {
    String a("Hello");
    String b("World");
    cout << (a.getData()) << (b.getData()) << endl;
    b = a;
    cout << (a.getData()) << (b.getData()) << endl;
    return 0;
}