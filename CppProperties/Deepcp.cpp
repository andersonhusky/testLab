#include<iostream>

#include<string>

using namespace std;

class Person{
public:
    Person(){cout << "默认构造" << endl;}
    Person(int a, int high){
        age = a;
        height = new int(high);
        cout << "有参构造" << endl;
    }
    Person(const Person& p){
        age = p.age;
        // 深拷贝
        // height = new int(*p.height);
        // 浅拷贝
        height = p.height;
    }
    ~Person(){
        cout << "析构函数" << endl;
        if(height!=nullptr){
            delete height;
            height = nullptr;
        }
    }

    int age;
    int* height;
};

int main(){
    Person* p1 = new Person(18, 160);
    cout << "p1年龄身高为：  " << p1->age << "  " << *p1->height << endl;
    Person p2(*p1);
    cout << "p2年龄身高为：  " << p2.age << "  " << *p2.height << endl;
    delete p1;
    cout << "p2年龄身高为：  " << p2.age << "  " << *p2.height << endl;
    return 0;
}