#include<iostream>
#include <vector>

using namespace std;

void Heap(vector<int>& vec, int loc, int tail){
    int left = loc*2+1, right=loc*2+2, next=loc;
    if(left<tail && right<tail){
        next = vec[left]>vec[right]? left: right;
    }
    else if(left<tail){
        next = left;
    }

    if(vec[next]>vec[loc]){
        swap(vec[next], vec[loc]);
        Heap(vec, next, tail);
    }
    return;
}

int main(){
    vector<int> testVec{1,2,45,8,46,8,1,12,75,15,46,41};
    for(int i=testVec.size()/2-1; i>=0; i--)
    {
        Heap(testVec, i, testVec.size());
    }
    for(int i=testVec.size()-1; i>=0; i--)
    {
        swap(testVec[0], testVec[i]);
        Heap(testVec, 0, i);
    }
    for(int a: testVec) cout << a << endl;
    return 0;
}