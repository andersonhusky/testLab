#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> input {0, 4, 3, 7, 5, 2, 3, 2, 5, 6, 3, 7, 4};
int main(){
    for(int i: input)   cout << i;
    cout << endl;
    sort(input.begin(), input.end());
    auto output_itr = unique(input.begin(), input.end());
    for(int i:input) cout << i;
    cout << endl;
    input.erase(output_itr, input.end());
    for(int i: input)  cout << i;
    cout << endl;
    return 0;
}