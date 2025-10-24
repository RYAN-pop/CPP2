#include<iostream>
using namespace std;

int main(){
    int a1[3][3],a2[3][3],a3[3][3];
    cout<<"a\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cin>>a1[i][j];
    }
    cout<<"b\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cin>>a2[i][j];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a3[i][j]=a1[i][0]*a2[0][j]+a1[i][1]*a2[1][j]+a1[i][2]*a2[2][j];
            cout<<a3[i][j]<<" ";
            
        }
        cout<<endl;   
    }
return 0;
}