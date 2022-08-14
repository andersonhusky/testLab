#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
    Point(){}
    Point(int x, int y):x(x), y(y){}
    
    static int cdot(const Point &p1, const Point &p2){
        return p1.x*p2.x + p1.y*p2.y;
    }
    static int xdot(const Point &p1, const Point &p2){
        return p1.x*p2.y-p1.y*p2.x;
    }
};


struct  Line
{
    Point p1, p2;
    Point line_vec;
    Line(const Point& p1, const Point& p2):p1(p1), p2(p2){
        line_vec = Point(p2.x-p1.x, p2.y-p1.y);
    }
    bool IsInter(const Line &L){
        bool quick_check = min(p1.x, p2.x) < max(L.p1.x, L.p2.x) &&
                        min(L.p1.x, L.p2.x) < max(p1.x, p2.x) &&
                        min(p1.y, p2.y) < max(L.p1.y, L.p2.y) &&
                        min(L.p1.y, L.p2.y) < max(p1.y, p2.y);
        if(quick_check){
            Point p1_Lp1 = Point(L.p1.x-p1.x, L.p1.y-p1.y);
            Point p1_Lp2 = Point(L.p2.x-p1.x, L.p2.y-p1.y);
            Point Lp1_p1 = Point(p1.x-L.p1.x, p1.y-L.p1.y);
            Point Lp1_p2 = Point(p2.x-L.p1.x, p2.y-L.p1.y);
            return Point::xdot(line_vec, p1_Lp1) * Point::xdot(line_vec, p1_Lp2)<0 && 
                            Point::xdot(L.line_vec, Lp1_p1) * Point::xdot(L.line_vec, Lp1_p2)<0;
        }
        return false;
    }
};

class LineVec
{
public:
    LineVec(){}
    void addLine(const Point &p1, const Point &p2){
        mLines.push_back(Line(p1, p2));
    }

public:
    vector<Line> mLines;

};

int main(){
    LineVec line_vec;
    line_vec.addLine(Point(0, 0), Point(1, 1));
    line_vec.addLine(Point(1, 0), Point(0, 1));
    cout << line_vec.mLines[0].IsInter(line_vec.mLines[1]) << endl;;
    return 1;
}