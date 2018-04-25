// 条款5:对应的new和delete要采用相同的格式
// 这里主要是删除单个对象和删除对象数组的问题,delete有多少个对象就会调用多少个析构函数

#include <iostream>
using namespace std;

typedef string array[10];

int main() {
    string* ptr = new array;
    cout << ptr << endl;
    delete [] ptr;
    return 0;
}