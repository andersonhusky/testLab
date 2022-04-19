#include<iostream>
#include <vector>

using namespace std;

void Merge(vector<int>& vec, int l, int r){
    if(l>=r) return;
    int mid = l + (r-l)/2;
    Merge(vec, l, mid);
    Merge(vec, mid+1, r);
    vector<int> tmp;
    int p1=l, p2=mid+1;
    while(p1<=mid && p2<r+1)
    {
        while(p1<=mid && vec[p1]<=vec[p2])
        {
            tmp.push_back(vec[p1++]);
        }
        while(p2<r+1 && vec[p1]>=vec[p2])
        {
            tmp.push_back(vec[p2++]);
        }
    }
    while(p1<=mid)   tmp.push_back(vec[p1++]);
    while(p2<r+1)  tmp.push_back(vec[p2++]);
    copy(tmp.begin(), tmp.end(), vec.begin()+l);
    return;
}

int main(){
    vector<int> testVec{1,2,45,8,46,8,1,12,75,15,46,41};
    Merge(testVec, 0, testVec.size()-1);
    for(int a: testVec) cout << a << endl;
    return 0;
}