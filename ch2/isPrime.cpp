#include<iostream>
using namespace std;
bool isPrime(int number){
    for(int a=2;a<number;a++)
        if(number%a==0) return false;
    return true;    
}

int main(){
    int n;
    while(1){
        cout <<"Please input a number:";
        cin >> n;
        cout <<isPrime(n) << endl;
    }
    return 0;
    
}

