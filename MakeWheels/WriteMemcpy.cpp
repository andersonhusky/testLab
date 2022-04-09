#include<iostream>
#include<vector>
#include<assert.h>
// 手写memcpy函数
using namespace std;

void* Memcpy(void* dest, void* src, size_t num){
    void* ret = dest;
    size_t i=0;
    assert(dest!=nullptr);
    assert(src!=nullptr);
    for(i=0; i<num; i++)
    {
        *(char*) dest = *(char*) src;
        dest = (char*)dest + 1;
        src = (char*) src + 1;
    }
    return ret;
}

int main(){
    int x;
    char strSrc[] = "Hello World! Fighting!";
    char strDest[20];
    cout << "Pleasr enter x" << endl;
    cin >> x;
    Memcpy(strDest, strSrc, x);
    strDest[x] = '\0';
    cout << "strDest: " << strDest << endl;
    return 0;
}