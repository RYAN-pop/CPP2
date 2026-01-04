#include<iostream>
#include<cmath>
using namespace std;

class test{
   
   int a;
   int b;
   public:
   test(int x,int y):a(x),b(y){}
   test operator+(const test& r)  {
      test x{a+r.a,b+r.b};
      cout<<a<<" "<<b<<endl;
      return x;
   }
   friend istream& operator>>(istream& input,test& A){
      input>>A.a>>A.b;
      return input;
   }
   friend ostream& operator<<(ostream& output,test& A){
      output<<A.a<<endl<<A.b<<endl;
      return output;
   }
};


int main(){
   cout<<"input:";
   test x(0,0);
   cin>>x;
   test y(3,4);
   test z=x+y;
   cout<<z;
}