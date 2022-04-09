#include<iostream>
#include <vector>
#include<list>
// 定义观察者基类，观察者基类中包含一个被观察者对象。观察者不断观察被观察者对象的状态并做出反应
// 继承观察者类，根据需要描述的观察者特征完成子类
// 定义被观察者基类，其有一个存放观察它的观察者的列表。需要实现更新观察者列表、在状态变化时通知观察者的函数
// 继承被观察者基类，完成函数定义
using namespace std;

class Subject;
// 观察者
class Observer{
protected:
    string name;
    Subject *sub;
public:
    Observer(string name, Subject *sub){
        this->name = name;
        this->sub = sub;
    }
    virtual void update()=0;
};

class StockObserver: public Observer{
public:
    StockObserver(string name, Subject* sub): Observer(name, sub){}
    void update();
};

class NBAObserver: public Observer{
public:
    NBAObserver(string name, Subject* sub): Observer(name, sub){}
    void update();
};

// 被观察者
class Subject{
protected:
    list<Observer*> observers;
public:
    string action;
    virtual void attach(Observer*)=0;
    virtual void detach(Observer*)=0;
    virtual void notify()=0;
};

class Secretary: public Subject{
public:
    void attach(Observer* observer){
        observers.push_back(observer);
    }
    void detach(Observer* observer){
        list<Observer*>::iterator iter = observers.begin();
        while(iter!=observers.end())
        {
            if((*iter)==observer){
                observers.erase(iter);
                return;
            }
            ++iter;
        }
    }
    void notify(){
        list<Observer*>::iterator iter = observers.begin();
        while(iter!=observers.end())
        {
            (*iter)->update();
            ++iter;
        }
    }
};

void StockObserver::update(){
    cout << name << "收到消息： " << sub->action <<endl;
    if(sub->action=="老板来了！"){
        cout << "我马上关闭股票，装作很认证工作的样子！" << endl;
    }
}

void NBAObserver::update(){
    cout << name << "收到消息： " << sub->action << endl;
    if(sub->action=="老板来了！"){
        cout << "我⻢上关闭 NBA，装做很认真⼯作的样⼦！ " << endl;
    }
}

int main(){
    Subject* Boss = new Secretary();
    Observer* xa = new NBAObserver("xa", Boss);
    Observer* xb = new NBAObserver("xa", Boss);
    Observer* xc = new StockObserver("xc", Boss);

    Boss->attach(xa);
    Boss->attach(xb);
    Boss->attach(xc);

    Boss->action = "去吃饭了！";
    Boss->notify();
    cout << endl;
    Boss->action = "老板来了！";
    Boss->notify();
    cout << endl;
    return 0;
}