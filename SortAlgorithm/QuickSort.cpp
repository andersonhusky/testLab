#include<iostream>
#include <vector>

using namespace std;

int QuickSort(vector<int>& vec, int l, int r){
    while(l<r)
    {
        while(l<r && vec[l]<=vec[r])
        {
            r--;
        }
        swap(vec[l], vec[r]);
        while(l<r && vec[l]<=vec[r])
        {
            l++;
        }
        swap(vec[l], vec[r]);
    }
    return l;
}

void Quick(vector<int>& vec, int l, int r){
    if(l>r) return;
    int randN = l + rand()%(r-l+1);
    swap(vec[l], vec[randN]);
    int mid = QuickSort(vec, l, r);
    Quick(vec, l, mid-1);
    Quick(vec, mid+1, r);
}

int main(){
    srand((unsigned)time(nullptr));
    vector<int> testVec{1,2,45,8,46,8,1,12,75,15,46,41};
    Quick(testVec, 0, testVec.size()-1);
    for(int a: testVec) cout << a << endl;
    return 0;
}