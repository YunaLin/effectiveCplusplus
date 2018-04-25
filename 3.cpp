// 条款３：尽量用new和delete而不要用malloc和free

// malloc和free没有构造函数和析构函数
// 最好不要混用malloc和new,另外注意malloc和free以及new和delete要成对使用
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
    // malloc返回的是void*，所以需要进行类型转换，也可以使用c++中的类型转换static_cast<string*>();
    // array1指向的是容纳10个string对象的内存空间，但是没有创建对象，但是new则是指向创建了10个string对象的数组
    string* array1 = (string*)malloc(sizeof(string)*10);
    string* array2 = new string[10];
    free(array1);
    delete []array2;
    cout << array1 << endl;
    cout << array2 << endl;
    return 0;
}
/*
malloc和new的区别：
（１）malloc是库函数，需要头文件支持，new是c++关键字
（２）malloc需要指明要分配内存的类型的大小，但是new不需要
（３）malloc没有构造函数和析构函数，但是new有，所以new是动态分配
（４）malloc的返回值是void*，但是new的返回值是对象类型的指针，不需要进行类型转换，符合类型安全的要求
（５）分配失败的话new抛出异常，但是malloc则是返回null
*/