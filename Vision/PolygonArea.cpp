#include <iostream>
#include <vector>

using namespace std;
struct  point
{
    int x, y;
    point(int x, int y):x(x), y(y){}
};

class Polygon{
public:
    Polygon(){};

    void AddPoint(int x, int y){
        mPoints.push_back(point(x, y));
    }

    float CalculateArea(){
        if(mPoints.size()<3)  return 0;
        int sum=0;
        for(int i=0; i<mPoints.size(); ++i){
            if(i==mPoints.size()-1){
                sum += mPoints[i].x*mPoints[0].y - mPoints[0].x*mPoints[i].y;
            }
            else{
                sum += mPoints[i].x*mPoints[i+1].y - mPoints[i+1].x*mPoints[i].y;
            }
        }
        return float(abs(sum))/2.f;
    }
public:
    vector<point> mPoints;
};
int main(){
    Polygon p;
    p.AddPoint(0, 0);
    p.AddPoint(3, 0);
    p.AddPoint(0, 4);
    p.AddPoint(-5, 4);
    cout << p.CalculateArea() << endl;
    return 1;
}