#include<iostream>
#include<cassert>

void divide(int a,int b){
    assert(b!=0);
    std::cout<<a/b<<std::endl;
}
int main(){
    divide(2,1);
    divide(3,0);
}