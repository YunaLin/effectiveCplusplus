// 条款7:预先准备好内存不够的情况
// new的做法是抛出异常，malloc的做法是返回NULL
#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;
// 宏定义
// 在try的语句块中执行可能出现错误的表达式并且抛出异常，在catch中捕捉异常并进行处理
// 如果try语句块中的new没有成功new会抛出异常，catch捕捉到bad_alloc异常后用assert(0)进行处理
// 断言assert是个宏，检查传给它的参数是否非零，如果非零就会发出一条错误信息并且调用abort
// 只能在调试时才能检查assert
#define NEW(PTR, TYPE) \
try {(PTR = new TYPE);} \
catch (bad_alloc&) {assert(0);}
#define MAX(a,b) ((a > b) ? a : b)

// try...throw...catch...的用法
// double func(double x, double y) {
//     if (y == 0) {
//         throw y;
//     }
//     return x/y;
// }
// int main() {
//     double res;
//     try {
//         res = func(9,0);
//     } catch (double) {
//         cout << "please make sure the divider is not zero" << endl;
//         exit(1);
//     }
// }
int main() {
    int* ptr = NULL;
    NEW(ptr, int);
    cout << ptr << endl;
    cout << MAX(2,4) << endl;
    return 0;
}