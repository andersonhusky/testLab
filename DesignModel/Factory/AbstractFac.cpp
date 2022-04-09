#include<iostream>
#include <vector>
#include<pthread.h>
// 为每个需要创建的类定义一一对应的工厂
using namespace std;

class Product{
public:
    Product(){}
    virtual void show()=0;
};

class Factory{
public:
    virtual Product* CreateProduce()=0;
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

// A工厂生产A实例
class FactoryA: public Factory{
public:
    Product* CreateProduce(){
        Product* product_ = nullptr;
        product_ = new ProductA();
        return product_;
    }
};

// B工厂生产B实例
class FactoryB: public Factory{
public:
    Product* CreateProduce(){
        Product* product_ = nullptr;
        product_ = new ProductB();
        return product_;
    }
};

int main(){
    Product* product_ = nullptr;
    auto MyFactoryA = new FactoryA();
    product_ = MyFactoryA->CreateProduce();
    product_->show();
    delete product_;

    auto MyFactoryB = new FactoryB();
    product_ = MyFactoryB->CreateProduce();
    product_->show();
    delete product_;

    return 0;
}