#include<iostream>
#include <vector>
#include<pthread.h>
// 建立工厂类，通过工厂类控制一系列类进行实例创建
using namespace std;
// 产品类，抽象类不能实例化
class Product{
public:
    Product(){}
    virtual void show()=0;
};

class ProductA: public Product{
public:
    ProductA(){}
    void show(){
        cout << "Product A create!" << endl;
    }
    ~ProductA(){}
};

class ProductB: public Product{
public:
    ProductB(){}
    void show(){
        cout << "Product B create!" << endl;
    }
    ~ProductB(){}
};

class simpleFactory{
public:
    simpleFactory(){}
    Product* createProduct(const string str){
        if(str == "productA")
            return new ProductA();
        else if(str=="productB")
            return new ProductB();
        return nullptr;
    }
};

int main(){
    simpleFactory obj;
    Product* pro;
    pro = obj.createProduct("productA");
    pro->show();
    delete pro;

    pro = obj.createProduct("productB");
    pro->show();
    delete pro;
    return 0;
}