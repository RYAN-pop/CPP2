#include<iostream>
#include<string>
using namespace std;


enum dir{N=0,E=1,S=2,W=3};
class point{
public:
    int x;
    int y;
    string d;
    point()=default;
    point(int xin,int yin,int dir):x(xin),y(yin){
        //x=xin;
        //y=yin;
        if(dir==N)      d="N";
        else if(dir==E) d="E";
        else if(dir==S) d="S";
        else if(dir==W) d="W";
    }
    void output(){
        cout<<x<<" "<<y<<" "<<d<<endl;
    }
};
struct Point{
    int x=1;
    int y=1;
    int d;

    void output(){
        cout<<x<<" "<<y<<" "<<d<<endl;
    }
};
ostream& operator <<(ostream &os, point &p){
    os<<p.x<<" "<<p.y<<" "<<p.d<<endl; return os;
}

 
void botMove(int r1,int r2,int &a,int &b,int &c){
    string m;
    cout << "your move\n";
    cin >> m;
    for(int i=0;i<m.length();i++){
        if(m[i]=='R')       c=(c+1)%4;
        else if(m[i]=='L')  c=(c+3)%4;
        else if(m[i]=='F'){
            if(c==0)        b++;
            else if(c==1)   a++;
            else if(c==2)   b--;
            else if(c==3)   a--;
            else            cout<<"error\n";
              
           
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
            
            
        }
    } 
    
    point p(a,b,c);
    p.output();

    
     
}
int main()
{
    //int a=10;// int a(10); int a{10}
    //int ar[10](1,2,3);
    int r1,r2,x,y,z; 
    string d;
    string command;
    cout<<"input range:\n";
    cin>>r1>>r2;
    //Point pArray[10]; // int ary[10];
    point p(1,1,1);
    point p1=p;
    auto p2=point(1,2,3);
    point pArray[3]={point(1,1,1),p,p2}; // int ary[10]={1,2};

    while(1){
        cout<<"input x,y and direction\n";
        cin>>command;
        if(command=="end"){
            cout<<"program end";
            break;
        }
        x=stoi(command);
        cin>>y>>d;
        if(d=="N")
            z=N;
        else if(d=="E")
            z=E;
        else if(d=="S")
            z=S;
        else if(d=="W")
            z=W;
       // botMove(r1,r2,x,y,z);
        Point p={x,y,z};
        botMove(r1,r2,p.x,p.y,p.d);
        //pArray[0]=p;
        
        
            
        
        

        

    }
point (x,y,z);
//point p1(p);

}