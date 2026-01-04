#include<iostream>
using namespace std;
class Student{
    public:
    int x;
    int y;
    //Student(int a,int b):x(a),y(b){}
    
    void output()const{
        cout<<x<<y;
    }
};
int main(){
    Student s{1,1};   
    s.output();
}