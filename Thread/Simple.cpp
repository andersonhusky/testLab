#include<iostream>
#include <vector>
#include <thread>

using namespace std;

void thread_test_(){
    std::cout << "hahahahaha" << std::endl;
}

int main(){
    std::thread t1(thread_test_);
    cout << "Main" << endl;
    t1.join();
    return 0;
}