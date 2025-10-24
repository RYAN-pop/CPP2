#include<iostream>
#include<string>
using namespace std;

class way{
    public:
    string direct;
    int n;

};
    
void botMove(int r1,int r2,int &a,int &b,int &c){
    string m;
    cout<<"your move\n";
    cin>>m;
    for(int i=0;i<m.length();i++){
        if(m[i]=='R')
             c=(c+1)%4;
        else if(m[i]=='L')
            c=(c+3)%4;
        else if(m[i]=='F'){
            if(a<0){
                cout<<"'lost ";
                a++;
                break;
            }
            else if(a>r1){
                cout<<"lost ";
                a--;
                break;
            }
            else if(b<0){
                cout<<"lost ";
                b++;
                break;
            }
            else if(b>r2){
                b--;
                cout<<"lost ";
                break;
            }
            
            else{
                if(c==0)
                    b++;
                else if(c==1)
                    a++;
                else if(c==2)
                    b--;
                else if(c==3)
                    a--;
            }
        }
    }
     
     cout<<a<<" "<<b;
}
int main()
{
    way w1;
    w1.direct="N";
    w1.n=0;
    way w2;
    w2.direct="E";
    w2.n=1;
    way w3;
    w3.direct="S";
    w3.n=2;
    way w4;
    w4.direct="W";
    w4.n=3;
    int r1,r2,x,y,z; 
    string p;
    string command;
    cout<<"input range:\n";
    cin>>r1>>r2;
    

    while(1){
        cout<<"input x,y and direction\n";
        cin>>command;
        if(command=="end"){
            cout<<"program end";
            break;
        }
        x=stoi(command);
        cin>>y>>p;
        
        
        if(p==w1.direct)
            z=w1.n;
        else if(p==w2.direct)
            z=w2.n;
         else if(p==w3.direct)
            z=w3.n;
        else if(p==w4.direct)
            z=w4.n;
        botMove(r1,r2,x,y,z);
        cout<<" ";
        if(z==w1.n)
            cout<<w1.direct<<endl;
        else if(z==w2.n)
            cout<<w2.direct<<endl;
        else if(z==w3.n)
            cout<<w3.direct<<endl;
        else if(z==w4.n)
            cout<<w4.direct<<endl;
            
        
        

        

    }

}