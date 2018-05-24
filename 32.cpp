// 条款32:尽可能地推迟变量的定义
#include <iostream>
using namespace std;

// 一旦定义一个类，就必须承担该类的构造和析构成本，但是在有的情况下定义并没有用到，所以最好在用到的时候再去定义变量
void encrypt(string& s) {}

string encryptPassword(const string& password) {
    if (password.length() < MIN_PASSWORD_LENGTH) {
        throw logic_error("password is too short");
    }

    string encrypted(password); // 通过拷贝构造函数定义并且进行初始化，因为使用缺省构造函数的开销要比赋值的开销大
    encrypt(encrypted);　　//　对字符串进行加密，该函数自行实现
    return encrypted;
}

int main() {
    return 0;
}

// 不仅要将变量定义推迟到必须使用他的时候，而且要尽量推迟到可以为他提供一个初始化参数为止
// 并且在变量使用的时候再对变量进行定义可以减少对变量的注释，这一点区别于c语言