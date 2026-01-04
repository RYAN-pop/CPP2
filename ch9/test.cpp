#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
    char a[3]="ab";
    cout<<a[2];//nothing
    char bString[10];
    strncpy(bString,"abcde",9);
    cout<<bString;
    char stringVar[10] = "The rain";
    strcat(stringVar, "in Spain");
    cout<<stringVar<<strlen(stringVar);
    char input;
    //cin.get(input);
    //cin.putback(input);
    //char again;
    //cin.get(input);
    //cout<<input;
    //cout.put('dhs');
    string line("abc");
    /*getline(cin,line);
    for(int i=0;i<line.length();i++){
        cout<<line[i]<<" ";*/
    string z;
    getline(cin,z);
    strcpy(a,"abc");
    cout<<a[2];
}