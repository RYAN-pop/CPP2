#include<iostream>
using namespace std;

class Point{
public:
    int x;
    int y;
    Point(int a,int b):x(a),y(b){};
    Point(Point ar[],int n){
       int xsum=0,ysum=0;
        for(int i=0;i<n;i++){
            xsum=xsum+ar[i].x;ysum=ysum+ar[i].y;
        }
        x=xsum;y=ysum;
    }
    
};
Point mysum(Point ar[],int n){
        int xsum=0,ysum=0;
        for(int i=0;i<n;i++){
            xsum=xsum+ar[i].x;ysum=ysum+ar[i].y;
        }
        return Point{xsum,ysum};
    };
int main(){
    Point p1{1,1};
    Point p2(2,2);
    Point p3=Point(2,3);    //{2,3};
    Point sum[3]={p1,p2,p3};
    cout<<mysum(sum,3).x<<endl;
    auto result=mysum(sum,3);
    cout<<result.x;
    Point result1(sum,3);
    cout<<result1.x;

    
}