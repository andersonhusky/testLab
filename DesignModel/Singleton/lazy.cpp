#include<iostream>
#include <vector>
#include<pthread.h>
#include<algorithm>
// 单例模式保证一个类只有一个实例，提供访问他的全局访问点
// 尽可能晚地创建对象实例，在第一次被引用的时候初始化，线程安全需要加锁
// 当对象使用频率不高占用内存大的时候适合使用
using namespace std;

class SingleInstance{
public:
    static SingleInstance* GetInstance(){
        if(ins == nullptr){
            pthread_mutex_lock(&mutex);
            if(ins ==nullptr){
                ins = new SingleInstance();
            }
            pthread_mutex_unlock(&mutex);
        }
        return ins;
    }
    ~SingleInstance(){};
    // 互斥锁
    static pthread_mutex_t mutex;
private:
    SingleInstance(){
        cout << "SingleInstance() 懒汉" << endl;
    }
    SingleInstance(const SingleInstance& other){};
    SingleInstance& operator=(const SingleInstance& other){
        return *this;
    }
    static SingleInstance* ins;
};

// 静态成员变量，在类内声明，在类外定义和初始化
SingleInstance* SingleInstance::ins = nullptr;
pthread_mutex_t SingleInstance::mutex;

int main(){
    SingleInstance* ins = SingleInstance::GetInstance();
    delete ins;
    return 0;
}