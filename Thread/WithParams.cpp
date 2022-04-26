#include<iostream>
#include <vector>
#include <thread>

using namespace std;

// vector作为传递参数需要用指针形式
void thread_test(vector<int> * vec){
    std::cout << "hahahahaha" << std::endl;
    for(int i=0, end=(*vec).size(); i<end; i++)
    {
        std:: cout << (*vec)[i];
        if(i==end-1)    std::cout << endl;
        else                    std::cout << ", ";
    }
}

int main(){
    vector<int> input{1,2,4,65,6};
    thread t1(thread_test, &input);
    cout << "Main" << endl;
    t1.join();
    return 0;
}