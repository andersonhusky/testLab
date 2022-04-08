#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
// 对于只知道有几行，用','隔开，每行不知道有多少个的字符串的输入，先用getline取一行，
// 然后用stringstream按照','划分，如
// 第一行输入一个数字N表示有N行
// 下面N行数据每行表示是一堆','分隔的字符串
// 5
// asdasd,asdn,kjas,njksand
// fdg,sdfui,vcxu,sd
// sdfn,erhiu,sd
// sdfne,asi,asidhji
// ernjk,enrio,asid
int N;
int main(){
    cin >> N;
    vector<vector<string>> v;
    v.reserve(N);
    string str;
    while(getline(cin, str))
    {
        vector<string> tmp;
        stringstream ss(str);
        while(getline(ss, str, ','))
        {
            tmp.push_back(str);
        }
        v.push_back(tmp);
    }

    cout << endl;
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            cout << v[i][j];
            if(j==v[i].size()-1)   cout << endl;
            else    cout << ", ";
        }
    }
    return 0;
}