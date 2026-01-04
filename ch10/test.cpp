#include<iostream>
using namespace std;

class test{
    int *data;
public:
    test(const test& other){
        data=new int(*other.data+1);
    }
    test &operator=(const test& other){
        delete data;
        data=new int(*other.data);
        return *this;
    }
    ~test(){
        delete data;
    }
    test(int value){
        data=new int(value);
    }
    friend ostream& operator<<(ostream& output,test x){
        output<<*x.data;
        return output;
    }
};

int main(){
    test p1(1);
    test p2=p1;
    test p3(3);
    //p1=p2=p3;
    cout<<p1<<endl<<p2<<endl<<p3;
}