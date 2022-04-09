#include<iostream>
#include <vector>
#include<cstring>

using namespace std;

class MyClass {
public:
    MyClass() :val(0) {
	cout << "构造 MyClass " << val << endl;
    }
    MyClass(int i):val(i){
	cout << "构造 MyClass " << val << endl;
    }

    MyClass(const MyClass &mc) {
	if (&mc != this) {
	    cout << "从" << mc.val << "拷贝构造 MyClass!" << endl;
	    val = mc.val;
	}
    }

    void operator = (const MyClass &mc) {
	if (&mc != this) {
	    cout << "将" << mc.val << "赋值给新的MyClass!" << endl;
	    val = mc.val;
        }
    }

    ~MyClass() {
	cout << "析构 MyClass " << val << endl;
    }


    int val;
};

// ①memcpy拷贝后的test、test1中元素指向同一个内存空间，析构时会出现悬空指针
// ②先分配空间，对复制语句更改，不会出现错误
// ☂对存储自己定义类的vector用memcpy拷贝
int main(){
    vector<int> test = {1, 2};
    cout << sizeof(test) << endl;
    cout << &test << endl;
    for(auto &t: test)
    {
        cout << &t << endl;
    }

    // 使用情况①
    // vector<int> test1;
    // cout << &test1 << endl;
    // memcpy(&test1, &test, sizeof(test));
    // for(auto& t: test1)
    // {
    //     cout << &t << endl;
    // }

    // 使用情况②
    vector<int> test1(test.size());  // 预先分配空间
    for(auto &t: test1){
        cout << &t << endl;
    }
    cout << &test1 << endl;
    memcpy(&test1[0], &test[0], sizeof(int)*test.size());
    for(auto &t: test1){
        cout << t << " " << &t << endl;
    }

    // 使用情况☂
    // vector<MyClass> test{ MyClass(1), MyClass(2) };
    // for (auto& mc : test) {
    //     cout << &mc << endl;
    // }

    // vector<MyClass> test1(test.size());
    // memcpy(&test1[0], &test[0], sizeof(test)*sizeof(MyClass));
    // for (auto& mc : test) {
    //     mc.val *= 10;
    //     cout << mc.val << " " << &mc << endl;
    // }
    return 0;
}