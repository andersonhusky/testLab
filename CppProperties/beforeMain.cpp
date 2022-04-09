#include<iostream>
#include <vector>

using namespace std;

// __attribute((constructor))标记函数在main开始之前执行，这里不能用cout不知道为什么
__attribute((constructor))void before(){
    printf("before main 1\n");
}

// 全局静态变量初始化先于main函数执行
int test(){
    cout << "before main! again!" << endl;
    return 1;
}
static int i = test();

int a = [](){
    cout << "before main!" << endl;
    return 0;
}();

int main(){
    cout << "main~~" << endl;
    return 0;
}