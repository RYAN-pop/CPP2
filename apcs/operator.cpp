#include<iostream>
using namespace std;
class Point;
ostream& operator <<(ostream &os, Point &p);
class Point{
    public:
    int x;
    int y;
    int d;
    //Point(int a):x(a),y(a),d(a){};
    Point operator+(const Point& p){
        auto result=Point{x+p.x, y+p.y, d+p.d};
        return result;

    }
    void printArray(Point a[],int n){
        for(int i=0;i<n;i++)
            cout<<a[i];
    }
};
ostream& operator <<(ostream &os, Point &p){
    os<<p.x<<" "<<p.y<<" "<<p.d<<endl; return os;
}
int main(){
Point p1={1,2,3},p2{2,4,6},pp=Point{1,1,1};
auto pp1=Point{1,2,3};
cout<<p1;
//auto p3=p1.add(p2);
auto p3=p1+p2;
auto p4=p1+Point{1,1,1};
cout<< p3;
Point pa[3]={{1,1,1},{1,2,3},{2,3,4}};
pa[0]={1,1,1};
//cout<<pa[0];
Point p;
p.printArray(pa,3);
}
