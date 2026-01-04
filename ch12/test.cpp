#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    //cout.precision(2);
    cout<<1.0<<endl;
    cout.setf(ios::fixed,ios::floatfield);
    cout.unsetf(ios::fixed);
    cout<<2.0;
    stringstream ss;
    string s;
    ss.str("a");
    ss.str("s");
    ss.clear();
    s=ss.str();
    cout<<s<<endl;
    cout<<sizeof("abcdef")<<endl;
    cout<<"a";
    cout.width(2);cout<<"b";
}