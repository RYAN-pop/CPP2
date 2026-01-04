#include<iostream>
using namespace std;

class Base{
protected:
    int a;
public:
    Base(int z){a=z;}
    Base& operator=(const Base& x){
        a=x.a;
        cout<<a;
        return *this;
    }
};
class Derived:public Base{
public:
    Derived(int z,int y):Base(z){}
    Derived& operator=(const Derived& x){
        Base::operator=(x);
        cout<<a+1;
        return *this;
    }
};
int main(){
    Derived b(1,2);
    Derived q(2,1);
    b=q;
}