#include<iostream>
#include <vector>
#include<memory>
// 装饰器模式允许想现有对象添加新功能
using namespace std;

// 抽象构件类
class Transform{
public:
    virtual void move()=0;
};

// 具体构件类
class Car: public Transform{
public:
    Car(){
        cout << "变形金刚是一辆车！" << endl;
    }
    void move(){
        cout << "在陆地上移动。" << endl;
    }
};

// 抽象装饰类
class Changer: public Transform{
public:
    Changer(shared_ptr<Transform> transform){
        this->transform = transform;
    }
    void move(){
        transform->move();
    }
private:
    shared_ptr<Transform> transform;
};

// 具体装饰类Robot
class Robot : public Changer{
public:
Robot(shared_ptr<Transform> transform) : Changer(transform){
std::cout << "变成机器⼈!" << std::endl;
}
void say(){
std::cout << "说话!" << std::endl;
    }
};

// 具体装饰类AirPlane
class Airplane: public Changer{
public:
    Airplane(shared_ptr<Transform> transform): Changer(transform){
        cout << "变成飞机！" << endl;
    }

    void say(){
        cout << "在天空飞翔" << endl;
    }
};

int main(){
    // 定义构件类
    shared_ptr<Transform> camaro = make_shared<Car>();
    camaro->move();
    cout << "-----------------" << endl;

    shared_ptr<Robot> bumblebee = make_shared<Robot>(camaro);
    bumblebee->move();
    bumblebee->say();
    cout << "-----------------" << endl;

    shared_ptr<Airplane> fly = make_shared<Airplane>(camaro);
    fly->move();
    fly->say();
    return 0;
}