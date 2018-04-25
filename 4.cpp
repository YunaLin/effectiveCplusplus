// 条款4:尽量使用c++风格的注释

#include <iostream>
using namespace std;

// c++提供行尾注释风格
int main() {
    int a, b;
    int res = (a > b) ? a : b;  // return the max value
    cout << res << endl;
    return 0;
}