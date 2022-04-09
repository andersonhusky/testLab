#include<iostream>
#include <vector>
#include<algorithm>
// 单例模式保证一个类只有一个实例，提供访问他的全局访问点
// 饿汉模式：饥不择食，在“单例类”定义的时候就进行实例化
// 方法：共有的静态成员函数GetInstance调用私有的构造函数，返回指向静态成员ins的指针；
// 只能通过这个静态成员方法构造，因为构造函数都设为私有
using namespace std;

class SingleInstance{
public:
    static SingleInstance* GetInstance(){
        static SingleInstance ins;
        return &ins;
    }
    ~SingleInstance(){}
private:
    SingleInstance(){
        cout << "SingleInstance() 饿汉" << endl;
    }
    SingleInstance(const SingleInstance& other){};
    SingleInstance& operator= (const SingleInstance& other){
        return *this;
    }
};

int main(){
    SingleInstance* ins = SingleInstance::GetInstance();
    return 0;
}