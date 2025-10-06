#include<iostream>
using namespace std;

bool isPrime(int number){

	for(int a=2;a<number;a++)
		if(number%a==0)
		return false;
		else
	
	return true;
}
		
	


int main(){
	while(1){
	
		int n;
		cout << "input number:";
		cin >> n;
		int number=n;
		cout << isPrime(n) << endl;
	}
}

