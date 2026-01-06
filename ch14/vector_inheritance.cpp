#include"../my.h"
class Base{
protected:
    int a,b;
public:
    Base(int a=0,int b=0):a(a),b(b){}
    Base& operator=(const Base& base){
        a=base.a;
        b=base.b;
        return *this;
    }
};
class Derived:public Base{
    int c,d;
public:
    Derived(){}
    //using Base::Base;
    Derived(int a,int b,int c,int d):Base(a,b),c(c),d(d){}
    Derived& operator=(const Derived& derived){
        Base::operator=(derived);
        c=derived.c;
        d=derived.d;
        return *this;
    }
    //Derived::Derived(){}
    friend ostream& operator<<(ostream& output,const Derived& other){
        output<<"derived: "
        <<other.a<<" "
        <<other.b<<" "
        <<other.c<<" "
        <<other.d<<endl;
        return output;
    }
};
class derivedVec:public vector<int>{
public:
    using vector<int>::vector;
    int& operator[](int index){
        if(index>=size()){
            cout<<"error";
            return vector<int>::operator[](0);
        }
        else return vector<int>::operator[](index);
    }
};
int main(){
    Derived b(1,2,3,4);
    Derived q;
    q=b;
    cout<<q;
    derivedVec v{1,2,3};
    for(int i=0;i<v.size()+2;i++){cout<<v[i]<<" ";}
}