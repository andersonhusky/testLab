#include<string>
#include<iostream>

using namespace std;

template<typename T>
class Shared_ptr{
public:
    // 空构造函数
    Shared_ptr():count(0), _ptr((T*)0){}
    // 构造函数，count为什么要用new构造？
    Shared_ptr(T* p):count(new int(1)), _ptr(p){}
    // 拷贝构造函数
    Shared_ptr(Shared_ptr<T>& other):count(&(++*other.count)), _ptr(other._ptr){}
    // 重载operator*,operator->，有指针的表现
    T& operator*(){return *_ptr;}
    T* operator->(){return _ptr;}       // 为什么返回即可？
    // 重载operator=，对原对象引用次数-1（为0的话delete），对新对象引用次数+1
    Shared_ptr<T>& operator=(Shared_ptr<T>& other){
        if(this==&other)    return *this;
        // =的Shared_ptr引用记数+1
        ++*other.count;
        // 当前的引用记数-1，为0时delete
        if(this->_ptr && (--*this->count==0)){
            delete count;
            delete _ptr;
            cout << "delete ptr =" << endl;
        }

        // 最后指向新的指针
        this->count = other.count;
        this->_ptr = other._ptr;
        return *this;
    }
    // 析构函数
    ~Shared_ptr(){
        if(_ptr && (--*count==0)){
            delete count;
            delete _ptr;
            cout << "delete ptr ~" << endl;
        }
    }

    // 查看引用次数
    int GetCount(){return *count;}
private:
    int* count;
    T* _ptr;
};

int main(int argc, const char * argv[])
{
	Shared_ptr<string> pstr(new string("abc"));
	cout << "pstr:"  << pstr.GetCount()  << " " << *pstr  << endl;

	Shared_ptr<string> pstr2(pstr);
	cout << "pstr:"  << pstr.GetCount()  << " " << *pstr  << endl;
	cout << "pstr2:" << pstr2.GetCount() << " " << *pstr2 << endl;

	Shared_ptr<string> pstr3(new string("hao"));
	cout << "pstr3:" << pstr3.GetCount() << " " << *pstr3 << endl;

	pstr3 = pstr2;
	cout << "pstr:"  << pstr.GetCount()  << " " << *pstr  << endl;
	cout << "pstr2:" << pstr2.GetCount() << " " << *pstr2 <<  endl;
	cout << "pstr3:" << pstr3.GetCount() << " " << *pstr3 << endl;


	return 0;
}