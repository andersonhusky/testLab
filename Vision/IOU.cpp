#include <iostream>

using namespace std;

struct Box{
    int x0, y0;     // 左上角
    int x1, y1;     // 右下角
    Box():x0(0), y0(0), x1(0), y1(0){}
    Box(int x0_, int y0_, int x1_, int y1_)
    :x0(x0_), y0(y0_), x1(x1_), y1(y1_){}

    float CalculateIOU(const Box &b){
        Box result(max(x0, b.x0), max(y0, b.y0), min(x1, b.x1), min(y1, b.y1));
        int A_area = CalculateArea();
        int B_area = b.CalculateArea();
        int inter_area = result.CalculateArea();
        if(A_area!=0 && B_area!=0)  return float(result.CalculateArea())/(float(A_area)+float(B_area) - inter_area);
        else return 0;
    }

    int CalculateArea()const {
        return (x0<x1 && y0<y1)? (x1-x0)*(y1-y0): 0;
    }
};

int main(){
    Box b1 = Box(0, 0 , 10, 10);
    Box b2 = Box(2, 2, 12, 12);
    Box b3 = Box(3, 5, 15, 8);
    cout << b1.CalculateIOU(b2) << endl;
    cout << b1.CalculateIOU(b3) << endl;
}