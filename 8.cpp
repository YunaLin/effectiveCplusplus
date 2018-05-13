// 条款8:写operator new和operator delete时要遵守常规
// 有关返回值，如果返回失败，抛出一个bad_alloc的异常
// c++标准要求，即使在内存分配失败的时候，也要返回一个合法的指针，希望出错处理函数能够释放别处内存
// 主要处理：请求为0的情况，内存分配失败的情况，子类继承父类的new函数的情况

void* operator new(size_t size) {
    // 对申请字节为0的情况进行处理，直接分配1个字节的内存
    if (size == 0) size = 1;
    // 这里有一个while循环，必须满足内存分配成功或者是抛出异常等才会退出循环
    while (1) {
        分配size字节的内存
        if (分配成功)
            return 内存指针
        // 当前出错处理函数
        new_handler globalHandler = set_new_handler(0);
        set_new_handler(globalHandler);
        if (globalHandler)
            (*globalHandler)();
        else
            throw std::bad_alloc();
    }
}

void operator delete(void* rawMemory) {
    if (rawMemory == 0) return;
    释放rawMemory指向的内存
    return;
}