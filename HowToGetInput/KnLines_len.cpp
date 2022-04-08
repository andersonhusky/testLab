#include<iostream>
#include<vector>

using namespace std;

// 对于每行的元素个数已知，并由空格分开的情况，使用cin即可, 如：
// 第一行输入一个数字N表示有N行
// 下面N行数据的第一个字符M表示这一行接下来有M个数据
// 5
// 3 1 2 3
// 4 1 2 3 4
// 1 10
// 2 15 22
// 5 1 2 3 4 5
int N;
int main(){
    cin >> N;
    cout << N << endl;
    string tmp;
    vector<vector<int>> stored;
    stored.reserve(N);
    for(int i=0; i<N; i++)
    {
        int len;
        cin >> len;
        vector<int> tmp(len, 0);
        for(int j=0; j<len; j++)
        {
            cin >> tmp[j];
        }
        stored.push_back(tmp);
    }

    cout << endl;
    for(int i=0; i<stored.size(); i++)
    {
        for(int j=0, end=stored[i].size(); j<end; j++)
        {
            cout << stored[i][j] << ", ";
        }
        cout << endl;
    }
}