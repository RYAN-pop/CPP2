#include<iostream>
using namespace std;

namespace test1{
    void greet(){
        cout<<"hi\n";
    }
}
namespace test2{
    void greet(){
        cout<<"hello\n";
    }
}
using test1::greet;
using test2::greet;
int main(){
    
    //using namespace test1;
    test1::greet();
    
    
    //using namespace test2;
    test2::greet();
    

}
