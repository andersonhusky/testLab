#include<iostream>
#include<vector>

using namespace std;

// 对于只知道有几行，每行不知道有多少个的字符串的输入，使用getchar()检车是否到换行符，如
// 第一行输入一个数字N表示有N行
// 下面N行数据每行表示一堆用空格隔开的字符串
// 5
// asdasd asdn kjas njksand
// fdg sdfui vcxu sd
// sdfn erhiu sd
// sdfne asi asidhji
// ernjk enrio asid
int N;
int main(){
    cin >> N;
    string S;
    vector<vector<string>> stored;
    vector<string> tmp;
    stored.reserve(N);
    while(cin >> S)
    {
        tmp.push_back(S);
        if(getchar()=='\n'){
            stored.push_back(tmp);
            tmp.clear();
        }
    }

    cout << endl;
    for(int i=0; i<stored.size(); i++)
    {
        for(int j=0; j<stored[i].size(); j++)
        {
            cout << stored[i][j];
            if(j==stored[i].size()-1)   cout << endl;
            else    cout << ", ";
        }
    }
    return 0;
}